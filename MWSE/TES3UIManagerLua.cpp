#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "TES3GameSetting.h"
#include "TES3Item.h"
#include "TES3ItemData.h"
#include "TES3MobileActor.h"
#include "TES3MobilePlayer.h"
#include "TES3NPC.h"
#include "TES3Reference.h"
#include "TES3WorldController.h"

#include "TES3UIElement.h"
#include "TES3UIManager.h"
#include "TES3UIMenuController.h"

#include "LuaUtil.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "Log.h"

namespace mwse {
	namespace lua {
		using TES3::UI::Element;
		using TES3::UI::UI_ID;
		using TES3::UI::Property;
		using TES3::UI::PropertyType;
		using TES3::UI::EventCallback;

		struct EventLuaCallback {
			Property id;
			sol::protected_function callback;
			EventCallback original;
		};
		static std::unordered_map<Element*, std::vector<EventLuaCallback>> eventMap;
		static std::unordered_map<Element*, void(__cdecl*)(Element*)> destroyMap;

		TES3::UI::Boolean __cdecl eventDispatcher(Element* owningWidget, Property eventID, int data0, int data1, Element* source) {
			LuaManager& luaManager = LuaManager::getInstance();
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Find dispatch target. Almost always source, but is owningWidget for 'focus' and 'unfocus' events.
			Element* target = source;
			if (eventID == Property::event_focus || eventID == Property::event_unfocus) {
				target = owningWidget;
			}

			// Handle event bubbling.
			while (target) {
				if (target->getProperty(PropertyType::Property, eventID).propertyValue == Property::inherit
					|| target->getProperty(PropertyType::EventCallback, eventID).eventCallback == nullptr) {

					target = target->parent;
				}
				else {
					break;
				}
			}

			auto iterElements = eventMap.find(target);
			if (iterElements != eventMap.end()) {
				for (const auto& eventLua : iterElements->second) {
					if (eventLua.id == eventID) {
						sol::table eventData = state.create_table();
						eventData["forwardSource"] = source;
						eventData["source"] = target;
						eventData["widget"] = owningWidget;
						eventData["id"] = eventID;
						eventData["data0"] = data0;
						eventData["data1"] = data1;

						// For mouse events, convert screen coordinates to element relative coordinates.
						if (eventID >= Property::event_mouse_leave && eventID <= Property::event_mouse_release) {
							eventData["relativeX"] = data0 - target->cached_screenX;
							eventData["relativeY"] = target->cached_screenY - data1;
						}

						// Note: sol::protected_function needs to be a local, as Lua functions can destroy it when modifying events.
						sol::protected_function callback = eventLua.callback;
						sol::protected_function_result result = callback(eventData);
						if (result.valid()) {
							sol::optional<bool> value = result;
							return value.value_or(true);
						}
						else {
							sol::error error = result;
							const char *errorSource = target->name.cString ? target->name.cString : "(unnamed)";
							log::getLog() << "Lua error encountered during UI event from element " << errorSource << ":" << std::endl << error.what() << std::endl;
							return true;
						}
					}
				}
			}

			return 1;
		}

		void __cdecl eventDestroyDispatcher(Element* source) {
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Dispatch Lua callback
			auto iterElements = eventMap.find(source);
			if (iterElements != eventMap.end()) {
				for (const auto& eventLua : iterElements->second) {
					if (eventLua.id == Property::event_destroy) {
						sol::table eventData = state.create_table();
						eventData["source"] = source;
						eventData["id"] = Property::event_destroy;

						// Note: sol::protected_function needs to be a local, as Lua functions can destroy it when modifying events.
						sol::protected_function callback = eventLua.callback;
						sol::protected_function_result result = callback();
						if (!result.valid()) {
							sol::error error = result;
							const char *errorSource = source->name.cString ? source->name.cString : "(unnamed)";
							log::getLog() << "Lua error encountered during UI event from element " << errorSource << ":" << std::endl << error.what() << std::endl;
						}

						break;
					}
				}
			}

			// Call original destroy callback
			auto callback = destroyMap[source];
			if (callback) {
				callback(source);
			}

			// Remove event mappings
			eventMap.erase(source);
			destroyMap.erase(source);
		}

		void registerUIEvent(Element& target, Property eventID, sol::protected_function callback) {
			// Save original callback, if present
			auto prevCallback = target.getProperty(PropertyType::EventCallback, eventID).eventCallback;
			if (prevCallback == eventDispatcher) {
				prevCallback = nullptr;
			}

			if (eventMap.find(&target) == eventMap.end()) {
				// Set a destroy hook the first time an event is added to an Element to allow cleanup
				// This callback uses PropertyType::Pointer instead of PropertyType::EventCallback
				auto prevDestroy = target.getProperty(PropertyType::Pointer, Property::event_destroy).ptrValue;
				target.setProperty(Property::event_destroy, static_cast<void*>(&eventDestroyDispatcher));
				destroyMap[&target] = static_cast<void (__cdecl*)(Element*)>(prevDestroy);
			}

			// Forward the event to our dispatcher
			if (eventID != Property::event_destroy) {
				target.setProperty(eventID, &eventDispatcher);
			}

			// Check for existing event to replace
			auto& elementEvents = eventMap[&target];
			for (auto& eventPair : elementEvents) {
				if (eventPair.id == eventID) {
					eventPair.callback = callback;
					return;
				}
			}

			// Add new event to list
			elementEvents.push_back(EventLuaCallback{ eventID, callback, prevCallback });
		}

		void unregisterUIEvent(Element& target, Property eventID) {
			auto& elementEvents = eventMap[&target];

			// Check for existing event
			for (auto it = elementEvents.begin(); it != elementEvents.end(); ++it) {
				if (it->id == eventID) {
					// Restore callback
					if (eventID != Property::event_destroy) {
						target.setProperty(eventID, it->original);
					}

					// Remove event
					elementEvents.erase(it);
					return;
				}
			}
		}

		TES3::UI::Boolean eventForwarder(sol::table eventData) {
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			Element* source = eventData["forwardSource"];
			Element* owningWidget = eventData["widget"];
			Property eventID = eventData["id"];
			int data0 = eventData["data0"];
			int data1 = eventData["data1"];

			// Use dispatch target resolved by eventDispatcher().
			Element* target = eventData["source"];

			auto iterElements = eventMap.find(target);
			if (iterElements != eventMap.end()) {
				for (const auto& eventLua : iterElements->second) {
					if (eventLua.id == eventID && eventLua.original) {
						// Call original callback.
						return eventLua.original(owningWidget, eventID, data0, data1, source);
					}
				}
			}
			return 1;
		}

		void triggerEvent(Element& target, Property eventID, int data0, int data1) {
			auto callback = target.getProperty(PropertyType::EventCallback, eventID).eventCallback;
			if (callback) {
				callback(&target, eventID, data0, data1, &target);
			}
		}

		const auto TES3_showDialogueMessage = reinterpret_cast<void (__cdecl*)(const char*, int, int)>(0x5C00A0);
		void showDialogueMessage(sol::table params) {
			const char* text = getOptionalParam<const char*>(params, "text", nullptr);
			int style = getOptionalParam<int>(params, "style", 0);
			int answerIndex = getOptionalParam<int>(params, "answerIndex", 0);

			TES3_showDialogueMessage(text, style, answerIndex);
		}

		//
		// Functions related to handling the InventorySelect menu.
		//

		static bool inventorySelectLuaCallbackCloseAfter = true;
		static sol::protected_function inventorySelectLuaCallback = sol::nil;
		bool __cdecl luaDispatchedSelectCallback(Element* element, Property property, int data0, int data1, Element * elementAgain) {
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			if (inventorySelectLuaCallback.valid()) {
				sol::table params = stateHandle.state.create_table();

				auto MenuInventorySelect_object = reinterpret_cast<TES3::BaseObject*>(element->getProperty(PropertyType::Pointer, *reinterpret_cast<Property*>(0x7D3B7A)).ptrValue);
				auto MenuInventorySelect_extra = reinterpret_cast<TES3::ItemData*>(element->getProperty(PropertyType::Pointer, *reinterpret_cast<Property*>(0x7D3C48)).ptrValue);
				auto MenuInventorySelect_count = element->getProperty(PropertyType::Integer, *reinterpret_cast<Property*>(0x7D3BCE)).integerValue;
				auto MenuInventorySelect_container = reinterpret_cast<TES3::Inventory*>(element->getProperty(PropertyType::Pointer, *reinterpret_cast<Property*>(0x7D3C32)).ptrValue);
				auto MenuInventorySelect_container_object = reinterpret_cast<TES3::Actor*>(element->getProperty(PropertyType::Pointer, *reinterpret_cast<Property*>(0x7D3C3C)).ptrValue);

				params["item"] = makeLuaObject(MenuInventorySelect_object);
				params["itemData"] = MenuInventorySelect_extra;
				params["count"] = MenuInventorySelect_extra ? MenuInventorySelect_extra->count : MenuInventorySelect_count;
				params["inventory"] = MenuInventorySelect_container;
				params["actor"] = makeLuaObject(MenuInventorySelect_container_object);

				sol::protected_function_result result =  inventorySelectLuaCallback(params);
				if (!result.valid()) {
					sol::error error = result;
					log::getLog() << "Lua error encountered during UI inventory select callback:" << std::endl << error.what() << std::endl;

					if (inventorySelectLuaCallbackCloseAfter) {
						TES3::UI::leaveMenuMode();
					}

					return false;
				}
			}

			if (inventorySelectLuaCallbackCloseAfter) {
				TES3::UI::leaveMenuMode();
			}

			return true;
		}

		static sol::protected_function inventorySelectLuaFilter = sol::nil;
		bool __cdecl luaDispatchedSelectFilter(Element* element, Property property, int data0, int data1, Element * elementAgain) {
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			if (inventorySelectLuaFilter.valid()) {
				sol::table params = stateHandle.state.create_table();

				auto MenuInventorySelect_filter_object = reinterpret_cast<TES3::BaseObject*>(element->getProperty(PropertyType::Pointer, *reinterpret_cast<Property*>(0x7D3C88)).ptrValue);
				auto MenuInventorySelect_filter_extra = reinterpret_cast<TES3::ItemData*>(element->getProperty(PropertyType::Pointer, *reinterpret_cast<Property*>(0x7D3C16)).ptrValue);

				params["item"] = makeLuaObject(MenuInventorySelect_filter_object);
				params["itemData"] = MenuInventorySelect_filter_extra;

				sol::protected_function_result result = inventorySelectLuaFilter(params);
				if (!result.valid()) {
					sol::error error = result;
					log::getLog() << "Lua error encountered during UI inventory select filtering for item '" << MenuInventorySelect_filter_object->getObjectID() << "':" << std::endl << error.what() << std::endl;

					return false;
				}
				else {
					sol::object resultObject = result;
					if (resultObject.is<bool>()) {
						return resultObject.as<bool>();
					}
				}
			}

			return true;
		}

		const auto TES3_UI_showSelectMenu = reinterpret_cast<void (__cdecl*)(TES3::Actor*, EventCallback*, const char*)>(0x5D35B0);
		void showSelectMenu(TES3::Actor * actor, EventCallback* callback, const char* titleText) {
			TES3_UI_showSelectMenu(actor, callback, titleText);
		}

		const std::unordered_map<std::string, EventCallback*> inventorySelectFilterIdMap = {
			{ "alembic", reinterpret_cast<EventCallback*>(0x59A1F0) },
			{ "calcinator", reinterpret_cast<EventCallback*>(0x59A160) },
			{ "enchanted", reinterpret_cast<EventCallback*>(0x5C6B40) },
			{ "ingredients", reinterpret_cast<EventCallback*>(0x59A220) },
			{ "mortar", reinterpret_cast<EventCallback*>(0x59A190) },
			{ "quickUse", reinterpret_cast<EventCallback*>(0x608A90) },
			{ "retort", reinterpret_cast<EventCallback*>(0x59A1C0) },
			{ "soulgemFilled", reinterpret_cast<EventCallback*>(0x5C6B00) },
		};

		void showInventorySelectMenu(sol::table params) {
			// Get our actor.
			TES3::Reference * actorRef = getOptionalParamExecutionReference(params);
			if (actorRef == nullptr) {
				actorRef = TES3::WorldController::get()->getMobilePlayer()->reference;
			}
			else if (!actorRef->baseObject->isActor()) {
				throw std::exception("Invalid reference passed to tes3ui.showInventorySelectMenu. Must be an actor.");
			}
			TES3::Actor * actor = static_cast<TES3::Actor*>(actorRef->baseObject);

			// Get our callback.
			EventCallback * callback = reinterpret_cast<EventCallback*>(&luaDispatchedSelectCallback);
			inventorySelectLuaCallback = getOptionalParam<sol::protected_function>(params, "callback", sol::nil);
			if (!inventorySelectLuaCallback.valid()) {
				throw std::exception("Invalid callback argument provided.");
			}

			// Get our filter.
			EventCallback * filter = nullptr;
			inventorySelectLuaFilter = sol::nil;
			sol::object maybeFilter = params["filter"];
			if (maybeFilter.is<sol::protected_function>()) {
				filter = reinterpret_cast<EventCallback*>(&luaDispatchedSelectFilter);
				inventorySelectLuaFilter = maybeFilter;
			}
			else if (maybeFilter.is<std::string>()) {
				std::string callbackId = maybeFilter.as<std::string>();
				auto findResult = inventorySelectFilterIdMap.find(callbackId);
				if (findResult == inventorySelectFilterIdMap.end()) {
					throw std::exception("Invalid filter ID provided.");
				}
				filter = findResult->second;
			}
			else {
				throw std::exception("Invalid filter argument provided. Must be a function, or a string ID.");
			}

			// And our title text.
			const char* titleText = getOptionalParam<const char*>(params, "title", nullptr);
			if (titleText == nullptr) {
				throw std::exception("Invalid title argument passed to tes3ui.showInventorySelectMenu.");
			}

			// Allow overwriting of our "no item found" text.
			auto sInventorySelectNoItems = TES3::DataHandler::get()->nonDynamicData->GMSTs[TES3::GMST::sInventorySelectNoItems];
			const char* oldNoResultsText = sInventorySelectNoItems->value.asString;
			const char* noResultsText = getOptionalParam<const char*>(params, "noResultsText", nullptr);
			if (noResultsText != nullptr) {
				sInventorySelectNoItems->value.asString = (char*)noResultsText;
			}

			// Do we close the menu after?
			inventorySelectLuaCallbackCloseAfter = getOptionalParam<bool>(params, "leaveMenuMode", !TES3::WorldController::get()->flagMenuMode);

			// Set our filter and show the menu.
			*reinterpret_cast<EventCallback**>(0x7D3CA0) = filter;
			showSelectMenu(actor, callback, titleText);

			// Restore the previous results text.
			if (noResultsText != nullptr) {
				sInventorySelectNoItems->value.asString = (char*)oldNoResultsText;
			}

			// If the menu was successfully shown, enter menu mode.
			auto MenuInventorySelect = *reinterpret_cast<UI_ID*>(0x7D3C14);
			if (TES3::UI::findMenu(MenuInventorySelect)) {
				TES3::UI::enterMenuMode(MenuInventorySelect);
			}
		}

		void bindTES3UIManager() {
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;
			auto tes3ui = state.create_named_table("tes3ui");

			tes3ui["registerID"] = TES3::UI::registerID;
			tes3ui["lookupID"] = TES3::UI::lookupID;
			tes3ui["registerProperty"] = TES3::UI::registerProperty;
			tes3ui.set_function("createMenu", [](sol::table args) {
				auto id = args.get<sol::optional<UI_ID>>("id");
				if (!id) {
					log::getLog() << "createMenu: id argument is required." << std::endl;
					return static_cast<Element*>(nullptr);
				}

				Element* menu = TES3::UI::createMenu(id.value());

				if (args.get<bool>("fixedFrame")) {
					menu->createFixedFrame(id.value(), 1);
					// Standard behaviours
					TES3::UI::preventInventoryMenuToggle(menu);
				}
				else if (args.get<bool>("dragFrame")) {
					menu->createDragFrame(id.value(), 1);
				}

				return menu;
			});
			tes3ui.set_function("createHelpLayerMenu", [](sol::table args) {
				auto id = args.get<sol::optional<UI_ID>>("id");
				if (!id) {
					log::getLog() << "createHelpLayerMenu: id argument is required." << std::endl;
					return static_cast<Element*>(nullptr);
				}
				return TES3::UI::createHelpLayerMenu(id.value());
			});
			tes3ui.set_function("createTooltipMenu", []() {
				return TES3::UI::createTooltipMenu(TES3::UI::UI_ID(TES3::UI::Property::HelpMenu));
			});
			tes3ui["findMenu"] = TES3::UI::findMenu;
			tes3ui["findHelpLayerMenu"] = TES3::UI::findHelpLayerMenu;
			tes3ui["getMenuOnTop"] = TES3::UI::getMenuOnTop;
			tes3ui["forcePlayerInventoryUpdate"] = []() {
				auto worldController = TES3::WorldController::get();
				auto playerMobile = worldController->getMobilePlayer();
				worldController->inventoryData->clearIcons(2);
				worldController->inventoryData->addInventoryItems(&playerMobile->npcInstance->inventory, 2);
				TES3::UI::updateInventoryMenuTiles();
			};
			tes3ui["menuMode"] = []() {
				return TES3::WorldController::get()->flagMenuMode;
			};
			tes3ui["enterMenuMode"] = TES3::UI::enterMenuMode;
			tes3ui["leaveMenuMode"] = TES3::UI::leaveMenuMode;
			tes3ui["acquireTextInput"] = TES3::UI::acquireTextInput;
			tes3ui["captureMouseDrag"] = TES3::UI::captureMouseDrag;
			tes3ui["getPalette"] = [](const char* name) {
				auto& luaManager = LuaManager::getInstance();
				auto stateHandle = luaManager.getThreadSafeStateHandle();
				sol::state_view state = stateHandle.state;
				auto colour = TES3::UI::getPaletteColour(TES3::UI::registerProperty(name));
				return state.create_table_with(1, colour.x, 2, colour.y, 3, colour.z);
			};
			tes3ui["updateInventoryTiles"] = &TES3::UI::updateInventoryMenuTiles;
			tes3ui["updateBarterMenuTiles"] = &TES3::UI::updateBarterMenuTiles;
			tes3ui["updateContentsMenuTiles"] = &TES3::UI::updateContentsMenuTiles;
			tes3ui["showInventorySelectMenu"] = &showInventorySelectMenu;
			tes3ui["updateInventorySelectTiles"] = []() -> sol::optional<int> {
				auto menu = TES3::UI::findMenu(*reinterpret_cast<TES3::UI::UI_ID*>(0x7D3C14));
				if (menu == nullptr) {
					return sol::optional<int>();
				}

				auto pane = menu->findChild(*reinterpret_cast<TES3::UI::UI_ID*>(0x7D821C));
				pane->destroyChildren();

				int count = TES3::UI::updateSelectInventoryTiles();

				menu->timingUpdate();

				return count;
			};
			tes3ui["getInventorySelectType"] = TES3::UI::getInventorySelectType;
			tes3ui["getServiceActor"] = []() {
				return mwse::lua::makeLuaObject(TES3::UI::getServiceActor());
			};
			tes3ui["showScrollMenu"] = &TES3::UI::showScrollMenu;
			tes3ui["showBookMenu"] = &TES3::UI::showBookMenu;
			tes3ui["logToConsole"] = [](const char* text, sol::optional<bool> isCommand) {
				TES3::UI::logToConsole(text, isCommand.value_or(false));
			};
			tes3ui["stealHelpMenu"] = &TES3::UI::stealHelpMenu;
			tes3ui["refreshTooltip"] = []() {
				TES3::WorldController::get()->menuController->menuInputController->updateObjectTooltip();
			};
			tes3ui["suppressTooltip"] = &TES3::UI::setSuppressingHelpMenu;
			tes3ui["showDialogueMessage"] = &showDialogueMessage;
			tes3ui["updateDialogDisposition"] = &TES3::UI::updateDialogDisposition;

			// Add binding for TES3::UI::TreeItem type.
			// TODO: Move this to its own file after TES3::UI::Tree has been made a template.
			{
				auto usertypeDefinition = state.create_simple_usertype<TES3::UI::TreeItem>();

				usertypeDefinition.set("id", &TES3::UI::TreeItem::key);
				usertypeDefinition.set("name", sol::property([](TES3::UI::TreeItem& self) {
					return TES3::UI::lookupID(self.key);
				}));
				usertypeDefinition.set("type", sol::property([](TES3::UI::TreeItem& self) {
					return unsigned int(self.valueType) & 0x7F;
				}));
				usertypeDefinition.set("value", sol::property([](TES3::UI::TreeItem& self) -> sol::object {
					auto& luaManager = mwse::lua::LuaManager::getInstance();
					auto stateHandle = luaManager.getThreadSafeStateHandle();
					sol::state& state = stateHandle.state;

					unsigned int type = unsigned int(self.valueType) & 0x7F;

					switch (type) {
					case TES3::UI::PropertyType::Integer:
						return sol::make_object(state, self.value.integerValue);
					case TES3::UI::PropertyType::Float:
						return sol::make_object(state, self.value.floatValue);
					case TES3::UI::PropertyType::Property:
						if (self.value.propertyValue == TES3::UI::Property::boolean_true) {
							return sol::make_object(state, true);
						}
						else if (self.value.propertyValue == TES3::UI::Property::boolean_false) {
							return sol::make_object(state, false);
						}
						else {
							return sol::make_object(state, self.value.propertyValue);
						}
					}
					return sol::nil;
				}));

				state.set_usertype("tes3uiProperty", usertypeDefinition);
			}
		}

	}
}

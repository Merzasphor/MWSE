#include "TES3UIManagerLua.h"

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

		bool __cdecl eventDispatcher(Element* owningWidget, Property eventID, int data0, int data1, Element* source) {
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

			return true;
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

		void registerUIEvent(Element* target, Property eventID, sol::protected_function callback) {
			// Save original callback, if present
			auto prevCallback = target->getProperty(PropertyType::EventCallback, eventID).eventCallback;
			if (prevCallback == eventDispatcher) {
				prevCallback = nullptr;
			}

			if (eventMap.find(target) == eventMap.end()) {
				// Set a destroy hook the first time an event is added to an Element to allow cleanup
				// This callback uses PropertyType::Pointer instead of PropertyType::EventCallback
				auto prevDestroy = target->getProperty(PropertyType::Pointer, Property::event_destroy).ptrValue;
				target->setProperty(Property::event_destroy, static_cast<void*>(&eventDestroyDispatcher));
				destroyMap[target] = static_cast<void (__cdecl*)(Element*)>(prevDestroy);
			}

			// Forward the event to our dispatcher
			if (eventID != Property::event_destroy) {
				target->setProperty(eventID, &eventDispatcher);
			}

			// Check for existing event to replace
			auto& elementEvents = eventMap[target];
			for (auto& eventPair : elementEvents) {
				if (eventPair.id == eventID) {
					eventPair.callback = callback;
					return;
				}
			}

			// Add new event to list
			elementEvents.push_back(EventLuaCallback{ eventID, callback, prevCallback });
		}

		void unregisterUIEvent(Element* target, Property eventID) {
			auto& elementEvents = eventMap[target];

			// Check for existing event
			for (auto it = elementEvents.begin(); it != elementEvents.end(); ++it) {
				if (it->id == eventID) {
					// Restore callback
					if (eventID != Property::event_destroy) {
						target->setProperty(eventID, it->original);
					}

					// Remove event
					elementEvents.erase(it);
					return;
				}
			}
		}

		bool eventForwarder(sol::table eventData) {
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

			return true;
		}

		void triggerEvent(Element* target, Property eventID, int data0, int data1) {
			auto callback = target->getProperty(PropertyType::EventCallback, eventID).eventCallback;
			if (callback) {
				callback(target, eventID, data0, data1, target);
			}
		}

		void bindTES3UIManager() {
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;
			auto tes3ui = state.create_named_table("tes3ui");

			tes3ui["registerID"] = TES3::UI::registerID;
			tes3ui["lookupID"] = TES3::UI::lookupID;
			tes3ui["registerProperty"] = TES3::UI::registerProperty;
			tes3ui["createMenu"] = TES3::UI::createMenu_lua;
			tes3ui["createHelpLayerMenu"] = TES3::UI::createHelpLayerMenu_lua;
			tes3ui["createTooltipMenu"] = TES3::UI::createTooltipMenu_lua;
			tes3ui["findMenu"] = TES3::UI::findMenu;
			tes3ui["findHelpLayerMenu"] = TES3::UI::findHelpLayerMenu;
			tes3ui["getMenuOnTop"] = TES3::UI::getMenuOnTop;
			tes3ui["forcePlayerInventoryUpdate"] = TES3::UI::forcePlayerInventoryUpdate;
			tes3ui["menuMode"] = TES3::UI::isInMenuMode;
			tes3ui["enterMenuMode"] = TES3::UI::enterMenuMode;
			tes3ui["leaveMenuMode"] = TES3::UI::leaveMenuMode;
			tes3ui["closeJournal"] = TES3::UI::closeJournal;
			tes3ui["acquireTextInput"] = TES3::UI::acquireTextInput;
			tes3ui["captureMouseDrag"] = TES3::UI::captureMouseDrag;
			tes3ui["getPalette"] = TES3::UI::getPalette_lua;
			tes3ui["updateInventoryTiles"] = TES3::UI::updateInventoryMenuTiles;
			tes3ui["updateBarterMenuTiles"] = TES3::UI::updateBarterMenuTiles;
			tes3ui["updateContentsMenuTiles"] = TES3::UI::updateContentsMenuTiles;
			tes3ui["showInventorySelectMenu"] = TES3::UI::showInventorySelectMenu_lua;
			tes3ui["updateInventorySelectTiles"] = TES3::UI::updateInventorySelectTiles_lua;
			tes3ui["getInventorySelectType"] = TES3::UI::getInventorySelectType;
			tes3ui["getServiceActor"] = TES3::UI::getServiceActor;
			tes3ui["showScrollMenu"] = TES3::UI::showScrollMenu;
			tes3ui["showBookMenu"] = TES3::UI::showBookMenu;
			tes3ui["logToConsole"] = TES3::UI::logToConsole_lua;
			tes3ui["stealHelpMenu"] = TES3::UI::stealHelpMenu;
			tes3ui["refreshTooltip"] = TES3::UI::refreshTooltip;
			tes3ui["suppressTooltip"] = TES3::UI::setSuppressingHelpMenu;
			tes3ui["showDialogueMessage"] = TES3::UI::showDialogueMessage;
			tes3ui["updateDialogDisposition"] = TES3::UI::updateDialogDisposition;
			tes3ui["updateSpellmakingMenu"] = TES3::UI::updateSpellmakingMenu;
			tes3ui["updateEnchantingMenu"] = TES3::UI::updateEnchantingMenu;

			// Add binding for TES3::UI::TreeItem type.
			// TODO: Move this to its own file after TES3::UI::Tree has been made a template.
			{
				auto usertypeDefinition = state.new_usertype<TES3::UI::TreeItem>("tes3uiProperty");

				usertypeDefinition["id"] = &TES3::UI::TreeItem::key;
				usertypeDefinition["name"] = sol::readonly_property(&TES3::UI::TreeItem::getName);
				usertypeDefinition["type"] = sol::readonly_property(&TES3::UI::TreeItem::getType);
				usertypeDefinition["value"] = sol::readonly_property(&TES3::UI::TreeItem::getValue_lua);
			}
		}

	}
}

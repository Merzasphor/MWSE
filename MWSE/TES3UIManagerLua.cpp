#include <cstdint>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "TES3UIElement.h"
#include "TES3UIManager.h"
#include "TES3UIMenuController.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "Log.h"

namespace mwse {
	namespace lua {
		using TES3::UI::Element;
		using TES3::UI::UI_ID;

		typedef std::pair<TES3::UI::Property, sol::protected_function> EventLuaCallback;
		static std::unordered_map<uintptr_t, std::vector<EventLuaCallback>> eventMap;

		TES3::UI::Boolean __cdecl eventDispatcher(Element* owningWidget, TES3::UI::Property eventID, int data0, int data1, Element* source) {
			sol::state& state = LuaManager::getInstance().getState();

			auto iterElements = eventMap.find(reinterpret_cast<uintptr_t>(source));
			if (iterElements != eventMap.end()) {
				for (const auto& eventPair : iterElements->second) {
					if (eventPair.first == eventID) {
						sol::table eventData = state.create_table();
						eventData["id"] = eventID;
						eventData["data0"] = data0;
						eventData["data1"] = data1;

						// Call into Lua
						auto result = eventPair.second(sol::make_object(state, source), eventData);
						if (!result.valid()) {
							sol::error error = result;
							log::getLog() << "Lua error encountered during UI event from element " << source->name.cString << ":" << std::endl << error.what() << std::endl;
						}
						// Default return true to event system
						sol::optional<TES3::UI::Boolean> ret = result;
						return ret.value_or(1);
					}
				}
			}
			return 1;
		}

		void __cdecl eventDestroyDispatcher(Element* source) {
			sol::state& state = LuaManager::getInstance().getState();

			// Dispatch Lua callback
			auto iterElements = eventMap.find(reinterpret_cast<uintptr_t>(source));
			if (iterElements != eventMap.end()) {
				for (const auto& eventPair : iterElements->second) {
					if (eventPair.first == TES3::UI::Property::event_destroy) {
						// Call into Lua
						auto result = eventPair.second(sol::make_object(state, source));
						if (!result.valid()) {
							sol::error error = result;
							log::getLog() << "Lua error encountered during UI event from element " << source->name.cString << ":" << std::endl << error.what() << std::endl;
						}
						break;
					}
				}
			}

			// Remove event mappings
			eventMap.erase(iterElements);

			// Remove text wrapping handler if source is a menu
			if (source == source->getTopLevelParent()) {
				TES3::UI::unregisterTextContainer(source);
			}
		}

		void registerUIEvent(Element& target, TES3::UI::Property eventID, sol::protected_function callback) {
			auto key = reinterpret_cast<uintptr_t>(&target);
			if (eventMap.find(key) == eventMap.end()) {
				// Set a destroy hook the first time an event is added to an Element to allow cleanup
				// This callback uses PropertyType::Pointer instead of PropertyType::EventCallback
				target.setProperty(eventID, static_cast<void*>(&eventDestroyDispatcher));
			}
			auto& elementEvents = eventMap[key];

			// Forward the event to our dispatcher
			if (eventID != TES3::UI::Property::event_destroy) {
				target.setProperty(eventID, &eventDispatcher);
			}

			// Check for existing event to replace
			for (auto& eventPair : elementEvents) {
				if (eventPair.first == eventID) {
					eventPair.second = callback;
					return;
				}
			}

			// Add new event to list
			elementEvents.push_back(std::make_pair(eventID, callback));
		}

		void unregisterUIEvent(Element& target, TES3::UI::Property eventID) {
			auto key = reinterpret_cast<uintptr_t>(&target);
			auto& elementEvents = eventMap[key];

			// Check for existing event
			for (auto it = elementEvents.begin(); it != elementEvents.end(); ++it) {
				if (it->first == eventID) {
					elementEvents.erase(it);
					return;
				}
			}
		}

		void bindTES3UIManager() {
			sol::state& state = LuaManager::getInstance().getState();
			auto tes3ui = state.create_named_table("tes3ui");

			tes3ui["registerID"] = TES3::UI::registerID;
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

					// Handle text reflow for TextLabel children, as the UI framework assumes static text
					static const auto propDragMenuOnResizing = TES3::UI::registerProperty("PartDragMenu_on_resizing");
					menu->setProperty(propDragMenuOnResizing, TES3::UI::onTextContainerResizing);
				}

				return menu;
			});
			tes3ui["findMenu"] = TES3::UI::findMenu;
			tes3ui["enterMenuMode"] = TES3::UI::enterMenuMode;
			tes3ui["leaveMenuMode"] = TES3::UI::leaveMenuMode;
			tes3ui["acquireTextInput"] = TES3::UI::acquireTextInput;
		}

	}
}

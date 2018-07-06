#include <array>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "TES3UIBlock.h"
#include "TES3UIManager.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "Log.h"

namespace mwse {
	namespace lua {
		using TES3::UI::Block;
		using TES3::UI::UI_ID;

		typedef std::pair<TES3::UI::Property, sol::protected_function> EventLuaCallback;
		static std::unordered_map<uintptr_t, std::vector<EventLuaCallback>> eventMap;

		const std::array<std::pair<const char *, TES3::UI::Property>, 19> standardNamedEvents = { {
			{ "mouseLeave", TES3::UI::Property::event_mouse_leave },
			{ "mouseOver", TES3::UI::Property::event_mouse_over },
			{ "mouseDown", TES3::UI::Property::event_mouse_down },
			{ "mouseClick", TES3::UI::Property::event_mouse_click },
			{ "mouseScrollUp", TES3::UI::Property::event_mouse_scroll_up },
			{ "mouseScrollDown", TES3::UI::Property::event_mouse_scroll_down },
			{ "mouseDoubleClick", TES3::UI::Property::event_mouse_double_click },
			{ "mouseStillIdle", TES3::UI::Property::event_mouse_still_idle },
			{ "mouseStillOver", TES3::UI::Property::event_mouse_still_over },
			{ "mouseStillPressedOutside", TES3::UI::Property::event_mouse_still_pressed_outside },
			{ "mouseStillPressed", TES3::UI::Property::event_mouse_still_pressed },
			{ "mouseRelease", TES3::UI::Property::event_mouse_release },
			{ "keyPress", TES3::UI::Property::event_key_press },
			{ "keyEnter", TES3::UI::Property::event_key_enter },
			{ "focus", TES3::UI::Property::event_focus },
			{ "unfocus", TES3::UI::Property::event_unfocus },
			{ "update", TES3::UI::Property::event_update },
			{ "preUpdate", TES3::UI::Property::event_pre_update },
			{ "destroy", TES3::UI::Property::event_destroy }
		} };

		const UI_ID idNull = static_cast<UI_ID>(TES3::UI::Property::null);

		TES3::UI::Property toBooleanProperty(bool x) {
			return x ? TES3::UI::Property::boolean_true : TES3::UI::Property::boolean_false;
		}

		bool toBoolean(TES3::UI::Property prop) {
			return prop == TES3::UI::Property::boolean_true;
		}

		TES3::UI::Boolean __cdecl eventDispatcher(Block* source, TES3::UI::Property eventID, int data0, int data1, Block*) {
			sol::state& state = LuaManager::getInstance().getState();

			auto iterBlocks = eventMap.find(reinterpret_cast<uintptr_t>(source));
			if (iterBlocks != eventMap.end()) {
				for (const auto& eventPair : iterBlocks->second) {
					if (eventPair.first == eventID) {
						sol::table eventData = state.create_table();
						eventData["id"] = eventID;
						eventData["data0"] = data0;
						eventData["data1"] = data1;

						// Call into Lua
						auto result = eventPair.second(sol::make_object(state, source), eventData);
						if (!result.valid()) {
							sol::error error = result;
							log::getLog() << "Lua error encountered during UI event from widget " << source->name.cString << ":" << std::endl << error.what() << std::endl;
						}
						// Default return true to event system
						sol::optional<bool> ret = result;
						return ret.value_or(1);
					}
				}
			}
			return 1;
		}

		void __cdecl eventDestroyDispatcher(Block* source) {
			sol::state& state = LuaManager::getInstance().getState();

			// Dispatch Lua callback
			auto iterBlocks = eventMap.find(reinterpret_cast<uintptr_t>(source));
			if (iterBlocks != eventMap.end()) {
				for (const auto& eventPair : iterBlocks->second) {
					if (eventPair.first == TES3::UI::Property::event_destroy) {
						// Call into Lua
						auto result = eventPair.second(sol::make_object(state, source));
						if (!result.valid()) {
							sol::error error = result;
							log::getLog() << "Lua error encountered during UI event from widget " << source->name.cString << ":" << std::endl << error.what() << std::endl;
						}
						break;
					}
				}
			}

			// Remove event mappings
			eventMap.erase(iterBlocks);
		}

		void registerEvent(Block& target, TES3::UI::Property eventID, sol::protected_function callback) {
			auto key = reinterpret_cast<uintptr_t>(&target);
			if (eventMap.find(key) == eventMap.end()) {
				// Set a destroy hook the first time an event is added to a Block to allow cleanup
				// This callback uses PropertyType::Pointer instead of PropertyType::EventCallback
				target.setProperty(eventID, static_cast<void*>(&eventDestroyDispatcher));
			}
			auto& blockEvents = eventMap[key];

			// Forward the event to our dispatcher
			if (eventID != TES3::UI::Property::event_destroy) {
				target.setProperty(eventID, &eventDispatcher);
			}

			// Check for existing event to replace
			for (auto& eventPair : blockEvents) {
				if (eventPair.first == eventID) {
					eventPair.second = callback;
					return;
				}
			}

			// Add new event to list
			blockEvents.push_back(std::make_pair(eventID, callback));
		}

		void unregisterEvent(Block& target, TES3::UI::Property eventID) {
			auto key = reinterpret_cast<uintptr_t>(&target);
			auto& blockEvents = eventMap[key];

			// Check for existing event
			for (auto it = blockEvents.begin(); it != blockEvents.end(); ++it) {
				if (it->first == eventID) {
					blockEvents.erase(it);
					return;
				}
			}
		}

		void bindTES3UIBlock() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<Block>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Read-only property bindings.
			usertypeDefinition.set("id", sol::readonly_property(&Block::id));
			usertypeDefinition.set("name", sol::readonly_property([](Block& self) { return self.name.cString; }));
			usertypeDefinition.set("parent", sol::readonly_property(&Block::parent));

			// Read-write property bindings.
			// Many properties also set lazy-update flags through setProperty.
			usertypeDefinition.set("borderAllSides", &TES3::UI::Block::borderAllSides);
			usertypeDefinition.set("borderLeft", &TES3::UI::Block::borderLeft);
			usertypeDefinition.set("borderRight", &TES3::UI::Block::borderRight);
			usertypeDefinition.set("borderBottom", &TES3::UI::Block::borderBottom);
			usertypeDefinition.set("borderTop", &TES3::UI::Block::borderTop);
			usertypeDefinition.set("paddingAllSides", &TES3::UI::Block::paddingAllSides);
			usertypeDefinition.set("paddingLeft", &TES3::UI::Block::paddingLeft);
			usertypeDefinition.set("paddingRight", &TES3::UI::Block::paddingRight);
			usertypeDefinition.set("paddingBottom", &TES3::UI::Block::paddingBottom);
			usertypeDefinition.set("paddingTop", &TES3::UI::Block::paddingTop);
			usertypeDefinition.set("font", sol::property(
				[](Block& self) { return self.font; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::font, value); }
			));
			usertypeDefinition.set("positionX", sol::property(
				[](Block& self) { return self.positionX; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::x_loc, value); }
			));
			usertypeDefinition.set("positionY", sol::property(
				[](Block& self) { return self.positionY; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::y_loc, value); }
			));
			usertypeDefinition.set("visible", sol::property(
				[](Block& self) { return self.visible != 0; },
				[](Block& self, bool value) { self.setVisible(value); }
			));
			usertypeDefinition.set("nodeMinX", &Block::nodeMinX);
			usertypeDefinition.set("nodeMaxX", &Block::nodeMaxX);
			usertypeDefinition.set("nodeMinY", &Block::nodeMinY);
			usertypeDefinition.set("nodeMaxY", &Block::nodeMaxY);
			usertypeDefinition.set("width", sol::property(
				[](Block& self) { return self.width; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::width, value); }
			));
			usertypeDefinition.set("height", sol::property(
				[](Block& self) { return self.height; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::height, value); }
			));
			usertypeDefinition.set("minWidth", sol::property(
				[](Block& self) { return self.minWidth; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::min_width, value); }
			));
			usertypeDefinition.set("minHeight", sol::property(
				[](Block& self) { return self.minHeight; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::min_height, value); }
			));
			usertypeDefinition.set("maxWidth", sol::property(
				[](Block& self) { return self.maxWidth; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::max_width, value); }
			));
			usertypeDefinition.set("maxHeight", sol::property(
				[](Block& self) { return self.maxHeight; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::max_height, value); }
			));
			usertypeDefinition.set("autoWidth", sol::property(
				[](Block& self) { return self.flagAutoWidth != 0; },
				[](Block& self, bool value) { self.setAutoWidth(value); }
			));
			usertypeDefinition.set("autoHeight", sol::property(
				[](Block& self) { return self.flagAutoHeight != 0; },
				[](Block& self, bool value) { self.setAutoHeight(value); }
			));
			usertypeDefinition.set("layoutWidthFraction", &TES3::UI::Block::layoutWidthFraction);
			usertypeDefinition.set("layoutHeightFraction", &TES3::UI::Block::layoutHeightFraction);
			usertypeDefinition.set("layoutOriginFractionX", &TES3::UI::Block::layoutOriginFractionX);
			usertypeDefinition.set("layoutOriginFractionY", &TES3::UI::Block::layoutOriginFractionY);
			usertypeDefinition.set("red", sol::property(
				[](Block& self) { return self.colourRed; },
				[](Block& self, float value) { self.setProperty(TES3::UI::Property::red, value); }
			));
			usertypeDefinition.set("green", sol::property(
				[](Block& self) { return self.colourGreen; },
				[](Block& self, float value) { self.setProperty(TES3::UI::Property::green, value); }
			));
			usertypeDefinition.set("blue", sol::property(
				[](Block& self) { return self.colourBlue; },
				[](Block& self, float value) { self.setProperty(TES3::UI::Property::blue, value); }
			));
			usertypeDefinition.set("alpha", sol::property(
				[](Block& self) { return self.colourAlpha; },
				[](Block& self, float value) { self.setProperty(TES3::UI::Property::alpha, value); }
			));
			usertypeDefinition.set("alignX", sol::property(
				[](Block& self) { self.getProperty(TES3::UI::PropertyType::Float, TES3::UI::Property::align_x); },
				[](Block& self, float value) { self.setProperty(TES3::UI::Property::align_x, value); }
			));
			usertypeDefinition.set("alignY", sol::property(
				[](Block& self) { self.getProperty(TES3::UI::PropertyType::Float, TES3::UI::Property::align_y); },
				[](Block& self, float value) { self.setProperty(TES3::UI::Property::align_y, value); }
			));
			usertypeDefinition.set("flowDirection", sol::property(
				[](Block& self) {
				auto flow = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::flow_direction).propertyValue;
				return (flow == TES3::UI::Property::top_to_bottom) ? "top_to_bottom" : "left_to_right";
			},
				[](Block& self, std::string value) {
				auto prop = (value == "top_to_bottom") ? TES3::UI::Property::top_to_bottom : TES3::UI::Property::left_to_right;
				self.setProperty(TES3::UI::Property::flow_direction, prop);
			}
			));
			usertypeDefinition.set("childOffsetX", sol::property(
				[](Block& self) { return self.childOffsetX; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::child_offset_x, value); }
			));
			usertypeDefinition.set("childOffsetY", sol::property(
				[](Block& self) { return self.childOffsetY; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::child_offset_y, value); }
			));
			usertypeDefinition.set("wrapText", sol::property(
				[](Block& self) {
					auto prop = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::wrap_text);
					return toBoolean(prop.propertyValue);
				},
				[](Block& self, bool value) { self.setProperty(TES3::UI::Property::wrap_text, toBooleanProperty(value)); }
			));
			usertypeDefinition.set("scaleMode", sol::property(
				[](Block& self) {
					auto prop = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::scale_mode);
					return toBoolean(prop.propertyValue);
				},
				[](Block& self, bool value) { self.setProperty(TES3::UI::Property::scale_mode, toBooleanProperty(value)); }
			));
			usertypeDefinition.set("justifyText", sol::property(
				[](Block& self) {
					auto justify = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::justify).propertyValue;
					if (justify == TES3::UI::Property::left) return "left";
					if (justify == TES3::UI::Property::center) return "center";
					if (justify == TES3::UI::Property::right) return "right";
					return "left";
				},
				[](Block& self, const std::string& value) {
					auto prop = TES3::UI::Property::left;
					if (value == "center") {
						prop = TES3::UI::Property::center;
					}
					else if (value == "right") {
						prop = TES3::UI::Property::right;
					}
					self.setProperty(TES3::UI::Property::justify, prop);
				}
			));
			usertypeDefinition.set("nodeOffsetX", sol::property(
				[](Block& self) { return self.nodeOffsetX; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::node_offset_x, value); }
			));
			usertypeDefinition.set("nodeOffsetY", sol::property(
				[](Block& self) { return self.nodeOffsetY; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::node_offset_y, value); }
			));
			usertypeDefinition.set("disabled", sol::property(
				[](Block& self) {
					auto prop = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::disabled);
					return toBoolean(prop.propertyValue);
				},
				[](Block& self, bool value) { self.setProperty(TES3::UI::Property::disabled, toBooleanProperty(value)); }
			));
			usertypeDefinition.set("scaleX", sol::property(
				[](Block& self) { return self.scaleX; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::image_scale_x, value); }
			));
			usertypeDefinition.set("scaleY", sol::property(
				[](Block& self) { return self.scaleY; },
				[](Block& self, int value) { self.setProperty(TES3::UI::Property::image_scale_y, value); }
			));
			usertypeDefinition.set("repeatKeys", sol::property(
				[](Block& self) {
					auto prop = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::repeat_keys);
					return toBoolean(prop.propertyValue);
				},
				[](Block& self, bool value) { self.setProperty(TES3::UI::Property::repeat_keys, toBooleanProperty(value)); }
			));
			usertypeDefinition.set("text", sol::property(
				[](Block& self) {
					static auto partTextInput = TES3::UI::registerProperty("PartTextInput");
					static auto partParaInput = TES3::UI::registerProperty("PartParagraphInput");
					std::string text(self.getText());

					// Special case code for input widgets, as getText's return value includes the text caret '|'
					// The game's method for removing it creates extra allocations that are inconvenient to free
					auto part = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::is_part).propertyValue;
					if (part == partTextInput || part == partParaInput) {
						auto i = text.find('|');
						if (i != std::string::npos) {
							text.erase(i, 1);
						}
					}
					return text;
				},
				[](Block& self, const char* value) { self.setText(value); }
			));

			// Custom property accessor functions.
			usertypeDefinition.set("getPropertyBool",
				[](Block& self, const char* propertyName) {
					TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
					auto b = self.getProperty(TES3::UI::PropertyType::Property, prop).propertyValue;
					return toBoolean(b);
				}
			);
			usertypeDefinition.set("getPropertyFloat",
				[](Block& self, const char* propertyName) {
					TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
					return self.getProperty(TES3::UI::PropertyType::Float, prop).floatValue;
				}
			);
			usertypeDefinition.set("getPropertyInt",
				[](Block& self, const char* propertyName) {
					TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
					return self.getProperty(TES3::UI::PropertyType::Integer, prop).integerValue;
				}
			);
			usertypeDefinition.set("setPropertyBool",
				[](Block& self, const char* propertyName, bool value) {
					TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
					self.setProperty(prop, toBooleanProperty(value) );
				}
			);
			usertypeDefinition.set("setPropertyFloat",
				[](Block& self, const char* propertyName, float value) {
					TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
					self.setProperty(prop, value);
				}
			);
			usertypeDefinition.set("setPropertyInt",
				[](Block& self, const char* propertyName, int value) {
					TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
					self.setProperty(prop, value);
				}
			);

			// Event functions.
			usertypeDefinition.set("register",
				[](Block& self, const std::string& eventID, sol::protected_function callback) {
					if (!callback.valid()) {
						log::getLog() << "UI register event has invalid callback: target " << self.name.cString << ", event " << eventID << std::endl;
						return;
					}

					// Map friendlier event names to standard UI events
					for (auto& x : standardNamedEvents) {
						if (eventID == x.first) {
							registerEvent(self, x.second, callback);
							return;
						}
					}

					// Check UI registry for custom event
					TES3::UI::Property prop = TES3::UI::registerProperty(eventID.c_str());
					registerEvent(self, prop, callback);
				}
			);
			usertypeDefinition.set("unregister",
				[](Block& self, const std::string& eventID) {
					// Map friendlier event names to standard UI events
					for (auto& x : standardNamedEvents) {
						if (eventID == x.first) {
							unregisterEvent(self, x.second);
							return;
						}
					}

					// Check UI registry for custom event
					TES3::UI::Property prop = TES3::UI::registerProperty(eventID.c_str());
					unregisterEvent(self, prop);
				}
			);

			// Layout functions.
			usertypeDefinition.set("findChild", [](Block& self, UI_ID id) { return self.findChild(id); });
			usertypeDefinition.set("updateLayout", [](Block& self) { self.performLayout(1); });

			// Creation/destruction functions.
			usertypeDefinition.set("createBlock", [](Block& self, sol::table args) {
				return self.createBlock(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createButton", [](Block& self, sol::table args) {
				auto button = self.createButton(args.get_or("id", idNull));
				auto text = args.get<sol::optional<const char*>>("text");
				if (text) {
					button->setText(text.value());
				}
				return button;
			});
			usertypeDefinition.set("createFillBar", [](Block& self, sol::table args) {
				return self.createFillBar(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createHorizontalScrollPane", [](Block& self, sol::table args) {
				return self.createHorizontalScrollPane(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createHypertext", [](Block& self, sol::table args) {
				return self.createHypertext(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createImage", [](Block& self, sol::table args) {
				auto path = args.get<sol::optional<const char*>>("path");
				if (path) {
					return self.createImage(args.get_or("id", idNull), path.value());
				}
				else {
					log::getLog() << "createImage: path argument is required." << std::endl;
				}
				return static_cast<Block*>(nullptr);
			});
			usertypeDefinition.set("createLabel", [](Block& self, sol::table args) {
				auto text = args.get<sol::optional<const char*>>("text");
				return self.createLabel(args.get_or("id", idNull), text.value_or("(nil)"));
			});
			usertypeDefinition.set("createNif", [](Block& self, sol::table args) {
				auto path = args.get<sol::optional<const char*>>("path");
				if (path) {
					return self.createNif(args.get_or("id", idNull), path.value());
				}
				else {
					log::getLog() << "createNif: path argument is required." << std::endl;
				}
				return static_cast<Block*>(nullptr);
			});
			usertypeDefinition.set("createParagraphInput", [](Block& self, sol::table args) {
				return self.createParagraphInput(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createSlider", [](Block& self, sol::table args) {
				return self.createSlider(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createSliderVertical", [](Block& self, sol::table args) {
				return self.createSliderVertical(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createTextInput", [](Block& self, sol::table args) {
				return self.createTextInput(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createTextSelect", [](Block& self, sol::table args) {
				return self.createTextSelect(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createThinBorder", [](Block& self, sol::table args) {
				return self.createNif(args.get_or("id", idNull), "menu_thin_border.nif");
			});
			usertypeDefinition.set("createVerticalScrollPane", [](Block& self, sol::table args) {
				return self.createVerticalScrollPane(args.get_or("id", idNull));
			});

			usertypeDefinition.set("destroy", [](Block& self) {
				UI_ID id = self.id;
				self.destroy();
				// Lua cleanup runs in destroy event handler
			});

			// Finish up our usertype.
			state.set_usertype("tes3uiBlock", usertypeDefinition);
		}
	}
}

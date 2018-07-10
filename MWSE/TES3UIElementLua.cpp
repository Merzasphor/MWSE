#include <string>
#include <unordered_map>

#include "TES3UIElement.h"
#include "TES3UIManager.h"
#include "TES3UIManagerLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "Log.h"

namespace mwse {
	namespace lua {
		using TES3::UI::Element;
		using TES3::UI::UI_ID;

		const std::unordered_map<std::string, TES3::UI::Property> standardNamedEvents = {
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
		};

		const UI_ID idNull = static_cast<UI_ID>(TES3::UI::Property::null);

		TES3::UI::Property toBooleanProperty(bool x) {
			return x ? TES3::UI::Property::boolean_true : TES3::UI::Property::boolean_false;
		}

		bool toBoolean(TES3::UI::Property prop) {
			return prop == TES3::UI::Property::boolean_true;
		}

		void bindTES3UIElement() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<Element>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Read-only property bindings.
			usertypeDefinition.set("id", sol::readonly_property(&Element::id));
			usertypeDefinition.set("name", sol::readonly_property([](Element& self) { return self.name.cString; }));
			usertypeDefinition.set("parent", sol::readonly_property(&Element::parent));
			usertypeDefinition.set("children", sol::readonly_property(
				[](const Element& self) {
					sol::table children;
					auto it = static_cast<const Element**>(self.vectorChildren.begin);
					auto end = static_cast<const Element**>(self.vectorChildren.end);
					for (int i = 1; it != end; ++it, ++i) {
						children[i] = *it;
					}
					return children;
				}
			));

			// Read-write property bindings.
			// Many properties also set lazy-update flags through setProperty.
			usertypeDefinition.set("borderAllSides", &TES3::UI::Element::borderAllSides);
			usertypeDefinition.set("borderLeft", &TES3::UI::Element::borderLeft);
			usertypeDefinition.set("borderRight", &TES3::UI::Element::borderRight);
			usertypeDefinition.set("borderBottom", &TES3::UI::Element::borderBottom);
			usertypeDefinition.set("borderTop", &TES3::UI::Element::borderTop);
			usertypeDefinition.set("paddingAllSides", &TES3::UI::Element::paddingAllSides);
			usertypeDefinition.set("paddingLeft", &TES3::UI::Element::paddingLeft);
			usertypeDefinition.set("paddingRight", &TES3::UI::Element::paddingRight);
			usertypeDefinition.set("paddingBottom", &TES3::UI::Element::paddingBottom);
			usertypeDefinition.set("paddingTop", &TES3::UI::Element::paddingTop);
			usertypeDefinition.set("font", sol::property(
				[](Element& self) { return self.font; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::font, value); }
			));
			usertypeDefinition.set("positionX", sol::property(
				[](Element& self) { return self.positionX; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::x_loc, value); }
			));
			usertypeDefinition.set("positionY", sol::property(
				[](Element& self) { return self.positionY; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::y_loc, value); }
			));
			usertypeDefinition.set("visible", sol::property(
				[](Element& self) { return self.visible != 0; },
				[](Element& self, bool value) { self.setVisible(value); }
			));
			usertypeDefinition.set("acceptMouseEvents", sol::property(
				[](Element& self) { return self.flagAcceptMouseEvents != 0; },
				[](Element& self, bool value) { self.flagAcceptMouseEvents = value; }
			));
			usertypeDefinition.set("nodeMinX", &Element::nodeMinX);
			usertypeDefinition.set("nodeMaxX", &Element::nodeMaxX);
			usertypeDefinition.set("nodeMinY", &Element::nodeMinY);
			usertypeDefinition.set("nodeMaxY", &Element::nodeMaxY);
			usertypeDefinition.set("width", sol::property(
				[](Element& self) { return self.width; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::width, value); }
			));
			usertypeDefinition.set("height", sol::property(
				[](Element& self) { return self.height; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::height, value); }
			));
			usertypeDefinition.set("minWidth", sol::property(
				[](Element& self) { return self.minWidth; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::min_width, value); }
			));
			usertypeDefinition.set("minHeight", sol::property(
				[](Element& self) { return self.minHeight; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::min_height, value); }
			));
			usertypeDefinition.set("maxWidth", sol::property(
				[](Element& self) { return self.maxWidth; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::max_width, value); }
			));
			usertypeDefinition.set("maxHeight", sol::property(
				[](Element& self) { return self.maxHeight; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::max_height, value); }
			));
			usertypeDefinition.set("autoWidth", sol::property(
				[](Element& self) { return self.flagAutoWidth != 0; },
				[](Element& self, bool value) { self.setAutoWidth(value); }
			));
			usertypeDefinition.set("autoHeight", sol::property(
				[](Element& self) { return self.flagAutoHeight != 0; },
				[](Element& self, bool value) { self.setAutoHeight(value); }
			));
			usertypeDefinition.set("layoutWidthFraction", &TES3::UI::Element::layoutWidthFraction);
			usertypeDefinition.set("layoutHeightFraction", &TES3::UI::Element::layoutHeightFraction);
			usertypeDefinition.set("layoutOriginFractionX", &TES3::UI::Element::layoutOriginFractionX);
			usertypeDefinition.set("layoutOriginFractionY", &TES3::UI::Element::layoutOriginFractionY);
			usertypeDefinition.set("red", sol::property(
				[](Element& self) { return self.colourRed; },
				[](Element& self, float value) { self.setProperty(TES3::UI::Property::red, value); }
			));
			usertypeDefinition.set("green", sol::property(
				[](Element& self) { return self.colourGreen; },
				[](Element& self, float value) { self.setProperty(TES3::UI::Property::green, value); }
			));
			usertypeDefinition.set("blue", sol::property(
				[](Element& self) { return self.colourBlue; },
				[](Element& self, float value) { self.setProperty(TES3::UI::Property::blue, value); }
			));
			usertypeDefinition.set("alpha", sol::property(
				[](Element& self) { return self.colourAlpha; },
				[](Element& self, float value) { self.setProperty(TES3::UI::Property::alpha, value); }
			));
			usertypeDefinition.set("alignX", sol::property(
				[](Element& self) { self.getProperty(TES3::UI::PropertyType::Float, TES3::UI::Property::align_x); },
				[](Element& self, float value) { self.setProperty(TES3::UI::Property::align_x, value); }
			));
			usertypeDefinition.set("alignY", sol::property(
				[](Element& self) { self.getProperty(TES3::UI::PropertyType::Float, TES3::UI::Property::align_y); },
				[](Element& self, float value) { self.setProperty(TES3::UI::Property::align_y, value); }
			));
			usertypeDefinition.set("flowDirection", sol::property(
				[](Element& self) {
				auto flow = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::flow_direction).propertyValue;
				return (flow == TES3::UI::Property::top_to_bottom) ? "top_to_bottom" : "left_to_right";
			},
				[](Element& self, std::string value) {
				auto prop = (value == "top_to_bottom") ? TES3::UI::Property::top_to_bottom : TES3::UI::Property::left_to_right;
				self.setProperty(TES3::UI::Property::flow_direction, prop);
			}
			));
			usertypeDefinition.set("childOffsetX", sol::property(
				[](Element& self) { return self.childOffsetX; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::child_offset_x, value); }
			));
			usertypeDefinition.set("childOffsetY", sol::property(
				[](Element& self) { return self.childOffsetY; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::child_offset_y, value); }
			));
			usertypeDefinition.set("wrapText", sol::property(
				[](Element& self) {
					auto prop = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::wrap_text);
					return toBoolean(prop.propertyValue);
				},
				[](Element& self, bool value) {
					self.setProperty(TES3::UI::Property::wrap_text, toBooleanProperty(value));

					// Set a handler to reflow wrapped text on updates
					TES3::UI::registerWrappedText(&self);
				}
			));
			usertypeDefinition.set("scaleMode", sol::property(
				[](Element& self) {
					auto prop = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::scale_mode);
					return toBoolean(prop.propertyValue);
				},
				[](Element& self, bool value) { self.setProperty(TES3::UI::Property::scale_mode, toBooleanProperty(value)); }
			));
			usertypeDefinition.set("justifyText", sol::property(
				[](Element& self) {
					auto justify = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::justify).propertyValue;
					if (justify == TES3::UI::Property::left) return "left";
					if (justify == TES3::UI::Property::center) return "center";
					if (justify == TES3::UI::Property::right) return "right";
					return "left";
				},
				[](Element& self, const std::string& value) {
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
				[](Element& self) { return self.nodeOffsetX; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::node_offset_x, value); }
			));
			usertypeDefinition.set("nodeOffsetY", sol::property(
				[](Element& self) { return self.nodeOffsetY; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::node_offset_y, value); }
			));
			usertypeDefinition.set("disabled", sol::property(
				[](Element& self) {
					auto prop = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::disabled);
					return toBoolean(prop.propertyValue);
				},
				[](Element& self, bool value) { self.setProperty(TES3::UI::Property::disabled, toBooleanProperty(value)); }
			));
			usertypeDefinition.set("scaleX", sol::property(
				[](Element& self) { return self.scaleX; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::image_scale_x, value); }
			));
			usertypeDefinition.set("scaleY", sol::property(
				[](Element& self) { return self.scaleY; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::image_scale_y, value); }
			));
			usertypeDefinition.set("repeatKeys", sol::property(
				[](Element& self) {
					auto prop = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::repeat_keys);
					return toBoolean(prop.propertyValue);
				},
				[](Element& self, bool value) { self.setProperty(TES3::UI::Property::repeat_keys, toBooleanProperty(value)); }
			));
			usertypeDefinition.set("text", sol::property(
				[](Element& self) {
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
				[](Element& self, const char* value) {
					// Set text and signal menu to re-layout.
					self.setText(value);
					self.getTopLevelParent()->timingUpdate();
				}
			));

			// Custom property accessor functions.
			usertypeDefinition.set("getPropertyBool",
				[](Element& self, const char* propertyName) {
					TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
					auto b = self.getProperty(TES3::UI::PropertyType::Property, prop).propertyValue;
					return toBoolean(b);
				}
			);
			usertypeDefinition.set("getPropertyFloat",
				[](Element& self, const char* propertyName) {
					TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
					return self.getProperty(TES3::UI::PropertyType::Float, prop).floatValue;
				}
			);
			usertypeDefinition.set("getPropertyInt",
				[](Element& self, const char* propertyName) {
					TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
					return self.getProperty(TES3::UI::PropertyType::Integer, prop).integerValue;
				}
			);
			usertypeDefinition.set("setPropertyBool",
				[](Element& self, const char* propertyName, bool value) {
					TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
					self.setProperty(prop, toBooleanProperty(value) );
				}
			);
			usertypeDefinition.set("setPropertyFloat",
				[](Element& self, const char* propertyName, float value) {
					TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
					self.setProperty(prop, value);
				}
			);
			usertypeDefinition.set("setPropertyInt",
				[](Element& self, const char* propertyName, int value) {
					TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
					self.setProperty(prop, value);
				}
			);

			// Event functions.
			usertypeDefinition.set("register",
				[](Element& self, const std::string& eventID, sol::protected_function callback) {
					if (!callback.valid()) {
						log::getLog() << "UI register event has invalid callback: target " << self.name.cString << ", event " << eventID << std::endl;
						return;
					}

					// Map friendlier event names to standard UI events
					auto it = standardNamedEvents.find(eventID);
					if (it != standardNamedEvents.end()) {
						registerUIEvent(self, it->second, callback);
						return;
					}

					// Check UI registry for custom event
					TES3::UI::Property prop = TES3::UI::registerProperty(eventID.c_str());
					registerUIEvent(self, prop, callback);
				}
			);
			usertypeDefinition.set("unregister",
				[](Element& self, const std::string& eventID) {
					// Map friendlier event names to standard UI events
					auto it = standardNamedEvents.find(eventID);
					if (it != standardNamedEvents.end()) {
						unregisterUIEvent(self, it->second);
						return;
					}

					// Check UI registry for custom event
					TES3::UI::Property prop = TES3::UI::registerProperty(eventID.c_str());
					unregisterUIEvent(self, prop);
				}
			);

			// Layout functions.
			usertypeDefinition.set("destroyChildren", [](Element& self) { return self.destroyChildren(); });
			usertypeDefinition.set("findChild", [](Element& self, UI_ID id) { return self.findChild(id); });
			usertypeDefinition.set("getTopLevelParent", [](Element& self) { return self.getTopLevelParent(); });
			usertypeDefinition.set("reorderChildren", [](Element& self, sol::object insertBefore, sol::object moveFrom, int count) {
				int indexInsertBefore, indexMoveFrom;

				if (insertBefore.is<int>()) {
					indexInsertBefore = insertBefore.as<int>();
				}
				else {
					indexInsertBefore = self.getIndexOfChild(insertBefore.as<Element*>());
					if (indexInsertBefore == -1) {
						return false;
					}
				}
				if (moveFrom.is<int>()) {
					indexMoveFrom = moveFrom.as<int>();
				}
				else {
					indexMoveFrom = self.getIndexOfChild(moveFrom.as<Element*>());
					if (indexMoveFrom == -1) {
						return false;
					}
				}

				return self.reorderChildren(indexInsertBefore, indexMoveFrom, count);
			});
			usertypeDefinition.set("updateLayout", [](Element& self) { self.performLayout(1); });

			// Creation/destruction functions.
			usertypeDefinition.set("createBlock", [](Element& self, sol::table args) {
				return self.createBlock(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createButton", [](Element& self, sol::table args) {
				auto button = self.createButton(args.get_or("id", idNull));
				auto text = args.get<sol::optional<const char*>>("text");
				if (text) {
					button->setText(text.value());
				}
				return button;
			});
			usertypeDefinition.set("createFillBar", [](Element& self, sol::table args) {
				return self.createFillBar(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createHorizontalScrollPane", [](Element& self, sol::table args) {
				auto scrollpane = self.createHorizontalScrollPane(args.get_or("id", idNull));

				// Add mouse wheel handlers (see event dispatch patch in TES3UIManager.cpp)
				scrollpane->setProperty(TES3::UI::Property::event_mouse_scroll_down, TES3::UI::onScrollPaneMousewheel);
				scrollpane->setProperty(TES3::UI::Property::event_mouse_scroll_up, TES3::UI::onScrollPaneMousewheel);
				return scrollpane;
			});
			usertypeDefinition.set("createHypertext", [](Element& self, sol::table args) {
				return self.createHypertext(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createImage", [](Element& self, sol::table args) {
				auto path = args.get<sol::optional<const char*>>("path");
				if (path) {
					return self.createImage(args.get_or("id", idNull), path.value());
				}
				else {
					log::getLog() << "createImage: path argument is required." << std::endl;
				}
				return static_cast<Element*>(nullptr);
			});
			usertypeDefinition.set("createLabel", [](Element& self, sol::table args) {
				auto text = args.get<sol::optional<const char*>>("text");
				return self.createLabel(args.get_or("id", idNull), text.value_or("(nil)"));
			});
			usertypeDefinition.set("createNif", [](Element& self, sol::table args) {
				auto path = args.get<sol::optional<const char*>>("path");
				if (path) {
					return self.createNif(args.get_or("id", idNull), path.value());
				}
				else {
					log::getLog() << "createNif: path argument is required." << std::endl;
				}
				return static_cast<Element*>(nullptr);
			});
			usertypeDefinition.set("createParagraphInput", [](Element& self, sol::table args) {
				return self.createParagraphInput(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createSlider", [](Element& self, sol::table args) {
				return self.createSlider(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createSliderVertical", [](Element& self, sol::table args) {
				return self.createSliderVertical(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createTextInput", [](Element& self, sol::table args) {
				return self.createTextInput(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createTextSelect", [](Element& self, sol::table args) {
				return self.createTextSelect(args.get_or("id", idNull));
			});
			usertypeDefinition.set("createThinBorder", [](Element& self, sol::table args) {
				return self.createNif(args.get_or("id", idNull), "menu_thin_border.nif");
			});
			usertypeDefinition.set("createVerticalScrollPane", [](Element& self, sol::table args) {
				auto scrollpane = self.createVerticalScrollPane(args.get_or("id", idNull));

				// Add mouse wheel handlers (see event dispatch patch in TES3UIManager.cpp)
				scrollpane->setProperty(TES3::UI::Property::event_mouse_scroll_down, TES3::UI::onScrollPaneMousewheel);
				scrollpane->setProperty(TES3::UI::Property::event_mouse_scroll_up, TES3::UI::onScrollPaneMousewheel);
				return scrollpane;
			});

			usertypeDefinition.set("destroy", [](Element& self) {
				UI_ID id = self.id;
				self.destroy();
				// Lua cleanup runs in destroy event handler
			});

			// Finish up our usertype.
			state.set_usertype("tes3uiElement", usertypeDefinition);
		}
	}
}

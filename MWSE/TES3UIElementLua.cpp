#include "TES3UIElementLua.h"

#include "LuaUtil.h"
#include "NIProperty.h"

#include "TES3GameFile.h"
#include "TES3Item.h"
#include "TES3ItemData.h"
#include "TES3MobileObject.h"
#include "TES3UIElement.h"
#include "TES3UIInventoryTile.h"
#include "TES3UIManager.h"
#include "TES3UIManagerLua.h"
#include "TES3UIWidgets.h"
#include "TES3UIWidgetsLua.h"

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

		template <typename T>
		sol::optional<T> valueDefaultAsNil(const T& value, T default) {
			sol::optional<T> x;
			if (value != default) {
				x = value;
			}
			return x;
		}

		TES3::UI::Property toBooleanProperty(bool x) {
			return x ? TES3::UI::Property::boolean_true : TES3::UI::Property::boolean_false;
		}

		bool toBool(TES3::UI::Property prop) {
			return prop == TES3::UI::Property::boolean_true;
		}

		// Helper function to build a table for an element's properties.
		void addPropertyToTable(sol::table& table, TES3::UI::TreeNode * node) {
			TES3::UI::TreeNode * sentinal = *reinterpret_cast<TES3::UI::TreeNode**>(0x7D1CEC);
			if (node == sentinal) {
				return;
			}

			table.add(node->item);

			addPropertyToTable(table, node->branchLess);
			addPropertyToTable(table, node->branchGreaterThanOrEqual);
		}

		void bindTES3UIElement() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<Element>("tes3uiElement");
			usertypeDefinition["new"] = sol::no_constructor;

			// Allow elements to be converted to strings using their object ID.
			usertypeDefinition[sol::meta_function::to_string] = [](Element& self) { return self.name.cString; };

			// Allow elements to be serialized to json using their ID/name.
			usertypeDefinition["__tojson"] = [](Element& self, sol::table state) {
				std::ostringstream ss;
				ss << "\"tes3uiElement:" << self.id << ":" << self.name.cString << "\"";
				return ss.str();
			};

			// Read-only property bindings.
			usertypeDefinition["id"] = sol::readonly_property(&Element::id);
			usertypeDefinition["name"] = sol::readonly_property([](Element& self) { return self.name.cString; });
			usertypeDefinition["parent"] = sol::readonly_property(&Element::parent);
			usertypeDefinition["children"] = sol::readonly_property(
				[](const Element& self) {
					auto& luaManager = mwse::lua::LuaManager::getInstance();
					auto stateHandle = luaManager.getThreadSafeStateHandle();
					sol::state& state = stateHandle.state;
					sol::table children = state.create_table();
					auto it = self.vectorChildren.begin;
					auto end = self.vectorChildren.end;
					for (int i = 1; it != end; ++it, ++i) {
						children[i] = *it;
					}
					return children;
				});
			usertypeDefinition["properties"] = sol::readonly_property([](const Element& self) {
				auto& luaManager = mwse::lua::LuaManager::getInstance();
				auto stateHandle = luaManager.getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table result = state.create_table();

				addPropertyToTable(result, self.properties.root->nextLeafOrRoot);

				return result;
			});
			usertypeDefinition["sceneNode"] = sol::readonly_property(&TES3::UI::Element::sceneNode);
			usertypeDefinition["contentType"] = sol::readonly_property([](Element& self) {
				switch (self.contentType) {
				case TES3::UI::Property::model:
					return "model";
				case TES3::UI::Property::text:
					return "text";
				case TES3::UI::Property::image:
					return "image";
				case TES3::UI::Property::rect:
					return "rect";
				default:
					return "layout";
				}
			});
			usertypeDefinition["widget"] = sol::readonly_property([](Element& self) { return makeWidget(self); });

			// Read-write property bindings.
			// Many properties also set lazy-update flags through setProperty.
			usertypeDefinition["borderAllSides"] = sol::property(
				[](Element& self) { return self.borderAllSides; },
				[](Element& self, sol::optional<int> value) { self.borderAllSides = value.value_or(0); });
			usertypeDefinition["borderLeft"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.borderLeft, -1); },
				[](Element& self, sol::optional<int> value) { self.borderLeft = value.value_or(-1); });
			usertypeDefinition["borderRight"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.borderRight, -1); },
				[](Element& self, sol::optional<int> value) { self.borderRight = value.value_or(-1); });
			usertypeDefinition["borderBottom"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.borderBottom, -1); },
				[](Element& self, sol::optional<int> value) { self.borderBottom = value.value_or(-1); });
			usertypeDefinition["borderTop"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.borderTop, -1); },
				[](Element& self, sol::optional<int> value) { self.borderTop = value.value_or(-1); });
			usertypeDefinition["paddingAllSides"] = sol::property(
				[](Element& self) { return self.paddingAllSides; },
				[](Element& self, sol::optional<int> value) { self.paddingAllSides = value.value_or(0); });
			usertypeDefinition["paddingLeft"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.paddingLeft, -1); },
				[](Element& self, sol::optional<int> value) { self.paddingLeft = value.value_or(-1); });
			usertypeDefinition["paddingRight"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.paddingRight, -1); },
				[](Element& self, sol::optional<int> value) { self.paddingRight = value.value_or(-1); });
			usertypeDefinition["paddingBottom"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.paddingBottom, -1); },
				[](Element& self, sol::optional<int> value) { self.paddingBottom = value.value_or(-1); });
			usertypeDefinition["paddingTop"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.paddingTop, -1); },
				[](Element& self, sol::optional<int> value) { self.paddingTop = value.value_or(-1); });
			usertypeDefinition["font"] = sol::property(
				[](Element& self) { return self.font; },
				[](Element& self, sol::optional<int> value) { self.setProperty(TES3::UI::Property::font, value.value_or(0)); });
			usertypeDefinition["positionX"] = sol::property(
				[](Element& self) { return self.positionX; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::x_loc, value); });
			usertypeDefinition["positionY"] = sol::property(
				[](Element& self) { return self.positionY; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::y_loc, value); });
			usertypeDefinition["visible"] = sol::property(
				[](Element& self) { return self.visible != 0; },
				[](Element& self, sol::optional<bool> value) { self.setVisible(value.value_or(true)); });
			usertypeDefinition["consumeMouseEvents"] = sol::property(
				[](Element& self) { return self.flagConsumeMouseEvents != 0; },
				[](Element& self, sol::optional<bool> value) { self.flagConsumeMouseEvents = value.value_or(true); });
			usertypeDefinition["nodeMinX"] = &Element::nodeMinX;
			usertypeDefinition["nodeMaxX"] = &Element::nodeMaxX;
			usertypeDefinition["nodeMinY"] = &Element::nodeMinY;
			usertypeDefinition["nodeMaxY"] = &Element::nodeMaxY;
			usertypeDefinition["width"] = sol::property(
				[](Element& self) { return self.width; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::width, value); });
			usertypeDefinition["height"] = sol::property(
				[](Element& self) { return self.height; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::height, value); });
			usertypeDefinition["minWidth"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.minWidth, INT32_MIN); },
				[](Element& self, sol::optional<int> value) { self.setProperty(TES3::UI::Property::min_width, value.value_or(INT32_MIN)); });
			usertypeDefinition["minHeight"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.minHeight, INT32_MIN); },
				[](Element& self, sol::optional<int> value) { self.setProperty(TES3::UI::Property::min_height, value.value_or(INT32_MIN)); });
			usertypeDefinition["maxWidth"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.maxWidth, INT32_MAX); },
				[](Element& self, sol::optional<int> value) { self.setProperty(TES3::UI::Property::max_width, value.value_or(INT32_MAX)); });
			usertypeDefinition["maxHeight"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.maxHeight, INT32_MAX); },
				[](Element& self, sol::optional<int> value) { self.setProperty(TES3::UI::Property::max_height, value.value_or(INT32_MAX)); });
			usertypeDefinition["autoWidth"] = sol::property(
				[](Element& self) { return self.flagAutoWidth != 0; },
				[](Element& self, bool value) { self.setAutoWidth(value); });
			usertypeDefinition["autoHeight"] = sol::property(
				[](Element& self) { return self.flagAutoHeight != 0; },
				[](Element& self, bool value) { self.setAutoHeight(value); });
			usertypeDefinition["widthProportional"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.widthProportional, -1.0f); },
				[](Element& self, sol::optional<double> value) { self.widthProportional = value.value_or(-1.0); });
			usertypeDefinition["heightProportional"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.heightProportional, -1.0f); },
				[](Element& self, sol::optional<double> value) { self.heightProportional = value.value_or(-1.0); });
			usertypeDefinition["absolutePosAlignX"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.absolutePosAlignX, -1.0f); },
				[](Element& self, sol::optional<double> value) { self.absolutePosAlignX = value.value_or(-1.0); });
			usertypeDefinition["absolutePosAlignY"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.absolutePosAlignY, -1.0f); },
				[](Element& self, sol::optional<double> value) { self.absolutePosAlignY = value.value_or(-1.0); });
			usertypeDefinition["color"] = sol::property(
				[](Element& self) {
					auto& luaManager = mwse::lua::LuaManager::getInstance();
					auto stateHandle = luaManager.getThreadSafeStateHandle();
					sol::state& state = stateHandle.state;
					return state.create_table_with(1, self.colourRed, 2, self.colourGreen, 3, self.colourBlue);
				},
				[](Element& self, sol::table c) {
					self.colourRed = c[1];
					self.colourGreen = c[2];
					self.colourBlue = c[3];
					self.flagUsesRGBA = 1;
				});
			usertypeDefinition["alpha"] = sol::property(
				[](Element& self) { return self.colourAlpha; },
				[](Element& self, float value) {
					self.colourAlpha = value;
					self.flagUsesRGBA = 1;
				});
			usertypeDefinition["flowDirection"] = sol::property(
				[](Element& self) {
					auto flow = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::flow_direction).propertyValue;
					return (flow == TES3::UI::Property::top_to_bottom) ? "top_to_bottom" : "left_to_right";
				},
				[](Element& self, std::string value) {
					auto prop = (value == "top_to_bottom") ? TES3::UI::Property::top_to_bottom : TES3::UI::Property::left_to_right;
					self.setProperty(TES3::UI::Property::flow_direction, prop);
				});
			usertypeDefinition["childAlignX"] = sol::property(
				[](Element& self) { return self.getProperty(TES3::UI::PropertyType::Float, TES3::UI::Property::align_x).floatValue; },
				[](Element& self, float value) { self.setProperty(TES3::UI::Property::align_x, value); });
			usertypeDefinition["childAlignY"] = sol::property(
				[](Element& self) { return self.getProperty(TES3::UI::PropertyType::Float, TES3::UI::Property::align_y).floatValue; },
				[](Element& self, float value) { self.setProperty(TES3::UI::Property::align_y, value); });
			usertypeDefinition["childOffsetX"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.childOffsetX, INT32_MAX); },
				[](Element& self, sol::optional<int> value) { self.setProperty(TES3::UI::Property::child_offset_x, value.value_or(INT32_MAX)); });
			usertypeDefinition["childOffsetY"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.childOffsetY, INT32_MAX); },
				[](Element& self, sol::optional<int> value) { self.setProperty(TES3::UI::Property::child_offset_y, value.value_or(INT32_MAX)); });
			usertypeDefinition["wrapText"] = sol::property(
				[](Element& self) {
					auto prop = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::wrap_text);
					return toBool(prop.propertyValue);
				},
				[](Element& self, bool value) {
					self.setProperty(TES3::UI::Property::wrap_text, toBooleanProperty(value));
					self.flagContentChanged = 1;
				});
			usertypeDefinition["justifyText"] = sol::property(
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
					self.flagContentChanged = 1;
				});
			usertypeDefinition["nodeOffsetX"] = sol::property(
				[](Element& self) { return self.nodeOffsetX; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::node_offset_x, value); });
			usertypeDefinition["nodeOffsetY"] = sol::property(
				[](Element& self) { return self.nodeOffsetY; },
				[](Element& self, int value) { self.setProperty(TES3::UI::Property::node_offset_y, value); });
			usertypeDefinition["disabled"] = sol::property(
				[](Element& self) {
					auto prop = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::disabled);
					return toBool(prop.propertyValue);
				},
				[](Element& self, bool value) { self.setProperty(TES3::UI::Property::disabled, toBooleanProperty(value)); });
			usertypeDefinition["texture"] = sol::property(
				[](Element& self) {
					return self.texture;
				},
				[](Element& self, NI::SourceTexture& texture) {
					self.texture = &texture;
					self.contentType = TES3::UI::Property::image;
					self.flagContentChanged = 1;
				});
			usertypeDefinition["scaleMode"] = sol::property(
				[](Element& self) {
					return toBool(self.scale_mode);
				},
				[](Element& self, bool value) {
					self.scale_mode = toBooleanProperty(value);
					self.flagContentChanged = 1;
				});
			usertypeDefinition["imageScaleX"] = sol::property(
				[](Element& self) { return self.imageScaleX; },
				[](Element& self, float value) {
					self.imageScaleX = value;
					self.flagContentChanged = 1;
				});
			usertypeDefinition["imageScaleY"] = sol::property(
				[](Element& self) { return self.imageScaleY; },
				[](Element& self, float value) {
					self.imageScaleY = value;
					self.flagContentChanged = 1;
				});
			usertypeDefinition["imageFilter"] = sol::property(
				[](Element& self) {
					if (self.sceneNode && self.texture) {
						using FilterMode = NI::TexturingProperty::FilterMode;
						auto prop = self.sceneNode->children.at(0)->getProperty(NI::PropertyType::Texturing);
						if (prop) {
							auto texturing = static_cast<NI::TexturingProperty*>(prop.get());
							return texturing->maps.at(0)->filterMode != FilterMode::NEAREST;
						}
					}
					return true;
				},
				[](Element& self, bool filter) {
					if (self.sceneNode && self.texture) {
						using FilterMode = NI::TexturingProperty::FilterMode;
						auto prop = self.sceneNode->children.at(0)->getProperty(NI::PropertyType::Texturing);
						if (prop) {
							auto texturing = static_cast<NI::TexturingProperty*>(prop.get());
							texturing->maps.at(0)->filterMode = filter ? FilterMode::BILERP : FilterMode::NEAREST;
							self.sceneNode->updateProperties();
						}
					}
				});
			usertypeDefinition["repeatKeys"] = sol::property(
				[](Element& self) {
					auto prop = self.getProperty(TES3::UI::PropertyType::Property, TES3::UI::Property::repeat_keys);
					return toBool(prop.propertyValue);
				},
				[](Element& self, bool value) { self.setProperty(TES3::UI::Property::repeat_keys, toBooleanProperty(value)); }
			);
			usertypeDefinition["text"] = sol::property(getWidgetText, setWidgetText);
			usertypeDefinition["contentPath"] = sol::property(
				[](Element& self) { return self.contentPath.cString; },
				[](Element& self, sol::optional<const char*> path) { self.setIcon(path.value_or("")); }
			);

			// Deprecated properties.
			// TODO: Remove in final release.
			usertypeDefinition["layoutWidthFraction"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.widthProportional, -1.0f); },
				[](Element& self, sol::optional<double> value) { self.widthProportional = value.value_or(-1.0); });
			usertypeDefinition["layoutHeightFraction"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.heightProportional, -1.0f); },
				[](Element& self, sol::optional<double> value) { self.heightProportional = value.value_or(-1.0); });
			usertypeDefinition["layoutOriginFractionX"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.absolutePosAlignX, -1.0f); },
				[](Element& self, sol::optional<double> value) { self.absolutePosAlignX = value.value_or(-1.0); });
			usertypeDefinition["layoutOriginFractionY"] = sol::property(
				[](Element& self) { return valueDefaultAsNil(self.absolutePosAlignY, -1.0f); },
				[](Element& self, sol::optional<double> value) { self.absolutePosAlignY = value.value_or(-1.0); });
			usertypeDefinition["alignX"] = sol::property(
				[](Element& self) { return self.getProperty(TES3::UI::PropertyType::Float, TES3::UI::Property::align_x).floatValue; },
				[](Element& self, float value) { self.setProperty(TES3::UI::Property::align_x, value); });
			usertypeDefinition["alignY"] = sol::property(
				[](Element& self) { return self.getProperty(TES3::UI::PropertyType::Float, TES3::UI::Property::align_y).floatValue; },
				[](Element& self, float value) { self.setProperty(TES3::UI::Property::align_y, value); });
			usertypeDefinition["acceptMouseEvents"] = sol::property(
				[](Element& self) { return self.flagConsumeMouseEvents != 0; },
				[](Element& self, sol::optional<bool> value) { self.flagConsumeMouseEvents = value.value_or(true); });

			// Custom property accessor functions.
			usertypeDefinition["hasProperty"] = [](Element& self, const char* propertyName) {
				return self.hasProperty(TES3::UI::registerProperty(propertyName));
			};
			usertypeDefinition["getPropertyType"] = [](Element& self, const char* propertyName) {
				return self.getPropertyType(TES3::UI::registerProperty(propertyName));
			};
			usertypeDefinition["getPropertyBool"] = [](Element& self, const char* propertyName) {
				TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
				auto b = self.getProperty(TES3::UI::PropertyType::Property, prop).propertyValue;
				return toBool(b);
			};
			usertypeDefinition["getPropertyFloat"] = [](Element& self, const char* propertyName) {
				TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
				return self.getProperty(TES3::UI::PropertyType::Float, prop).floatValue;
			};
			usertypeDefinition["getPropertyInt"] = [](Element& self, const char* propertyName) {
				TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
				return self.getProperty(TES3::UI::PropertyType::Integer, prop).integerValue;
			};
			usertypeDefinition["getPropertyObject"] = [](Element& self, const char* propertyName, sol::optional<std::string> typeCast) -> sol::object {
				auto& luaManager = mwse::lua::LuaManager::getInstance();
				auto stateHandle = luaManager.getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;

				TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
				auto ptr = self.getProperty(TES3::UI::PropertyType::Pointer, prop).ptrValue;

				if (!ptr) {
					return sol::nil;
				}

				if (!typeCast) {
					auto object = static_cast<TES3::BaseObject*>(ptr);

					switch (object->objectType) {
					case TES3::ObjectType::MobileCreature:
					case TES3::ObjectType::MobileNPC:
					case TES3::ObjectType::MobilePlayer:
						return TES3::MobileObject::getOrCreateLuaObject(state, static_cast<TES3::MobileObject*>(ptr));
					default:
						return TES3::BaseObject::getOrCreateLuaObject(state, static_cast<TES3::BaseObject*>(ptr));
					}
				}
				else {
					if (typeCast.value() == "tes3itemData") {
						return sol::make_object(state, static_cast<TES3::ItemData*>(ptr));
					}
					else if (typeCast.value() == "tes3gameFile") {
						return sol::make_object(state, static_cast<TES3::GameFile*>(ptr));
					}
					else if (typeCast.value() == "tes3inventoryTile") {
						return sol::make_object(state, static_cast<TES3::UI::InventoryTile*>(ptr));
					}
					else if (typeCast.value() == "tes3uiElement") {
						return sol::make_object(state, static_cast<TES3::UI::Element*>(ptr));
					}
					return sol::nil;
				}
			};
			usertypeDefinition["setPropertyBool"] = [](Element& self, const char* propertyName, bool value) {
				TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
				self.setProperty(prop, toBooleanProperty(value));
			};
			usertypeDefinition["setPropertyFloat"] = [](Element& self, const char* propertyName, float value) {
				TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
				self.setProperty(prop, value);
			};
			usertypeDefinition["setPropertyInt"] = [](Element& self, const char* propertyName, int value) {
				TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
				self.setProperty(prop, value);
			};
			usertypeDefinition["setPropertyObject"] = [](Element& self, const char* propertyName, TES3::BaseObject* value) {
				TES3::UI::Property prop = TES3::UI::registerProperty(propertyName);
				self.setProperty(prop, value);
			};

			// Event functions.
			usertypeDefinition["register"] = [](Element& self, const std::string& eventID, sol::object callback) {
				// Callback is supposed to be an address. Dangerous advanced usage, sets the actual property.
				if (callback.is<unsigned int>()) {
					// Map friendlier event names to standard UI events1
					auto it = standardNamedEvents.find(eventID);
					if (it != standardNamedEvents.end()) {
						self.setProperty(it->second, reinterpret_cast<TES3::UI::EventCallback>(callback.as<unsigned int>()));
						return;
					}

					// Check UI registry for custom event
					TES3::UI::Property prop = TES3::UI::registerProperty(eventID.c_str());
					self.setProperty(prop, reinterpret_cast<TES3::UI::EventCallback>(callback.as<unsigned int>()));
				}

				// Callback is a lua event, put it into our custom handler system.
				else if (callback.is<sol::protected_function>()) {
					if (!callback.valid()) {
						const char *errorSource = self.name.cString ? self.name.cString : "(unnamed)";
						log::getLog() << "UI register event has invalid callback: target " << errorSource << ", event " << eventID << std::endl;
						logStackTrace();
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
					registerUIEvent(self, prop, callback.as<sol::protected_function>());
				}
				
				// Unrecognized type, spit an error.
				else {
					const char *errorSource = self.name.cString ? self.name.cString : "(unnamed)";
					log::getLog() << "UI register event has invalid callback type: target " << errorSource << ", event " << eventID << std::endl;
					logStackTrace();
				}
			};
			usertypeDefinition["unregister"] = [](Element& self, const std::string& eventID) {
				// Map friendlier event names to standard UI events
				auto it = standardNamedEvents.find(eventID);
				if (it != standardNamedEvents.end()) {
					unregisterUIEvent(self, it->second);
					return;
				}

				// Check UI registry for custom event
				TES3::UI::Property prop = TES3::UI::registerProperty(eventID.c_str());
				unregisterUIEvent(self, prop);
			};
			usertypeDefinition["forwardEvent"] = [](Element& self, sol::table eventData) {
				if (eventData.valid()) {
					eventForwarder(eventData);
				}
			};
			usertypeDefinition["triggerEvent"] = [](Element& self, sol::object args) {
				if (args.get_type() == sol::type::table) {
					auto eventData = args.as<sol::table>();
					triggerEvent(self, eventData["id"], eventData["data0"], eventData["data1"]);
					return;
				}

				// Map friendlier event names to standard UI events
				auto eventID = args.as<std::string>();
				auto it = standardNamedEvents.find(eventID);
				if (it != standardNamedEvents.end()) {
					triggerEvent(self, it->second, 0, 0);
					return;
				}

				// Check UI registry for custom event
				TES3::UI::Property prop = TES3::UI::registerProperty(eventID.c_str());
				triggerEvent(self, prop, 0, 0);
			};

			// Layout functions.
			usertypeDefinition["destroyChildren"] = [](Element& self) { return self.destroyChildren(); };
			usertypeDefinition["findChild"] = [](Element& self, UI_ID id) { return self.findChild(id); };
			usertypeDefinition["getContentElement"] = [](Element& self) { return self.getContentElement(); };
			usertypeDefinition["getTopLevelMenu"] = [](Element& self) { return self.getTopLevelParent(); };
			usertypeDefinition["getTopLevelParent"] = [](Element& self) { return self.getTopLevelParent(); };
			usertypeDefinition["reorderChildren"] = [](Element& self, sol::object insertBefore, sol::object moveFrom, int count) {
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
			};
			usertypeDefinition["updateLayout"] = [](Element& self) { self.performLayout(1); };

			// Creation/destruction functions.
			usertypeDefinition["createBlock"] = [](Element& self, sol::optional<sol::table> args) {
				if (args) {
					return self.createBlock(args.value().get_or("id", idNull));
				}
				else {
					return self.createBlock(idNull);
				}
			};
			usertypeDefinition["createButton"] = [](Element& self, sol::optional<sol::table> args) {
				Element * button = nullptr;
				if (args) {
					button = self.createButton(args.value().get_or("id", idNull));

					auto text = args.value().get<sol::optional<const char*>>("text");
					if (text) {
						button->setText(text.value());
					}
				}
				else {
					button = self.createButton(idNull);
				}

				return button;
			};
			usertypeDefinition["createDivider"] = [](Element& self, sol::optional<sol::table> args) {
				Element * image = nullptr;
				if (args) {
					image = self.createImage(args.value().get_or("id", idNull), "Textures\\menu_divider.tga");
				}
				else {
					image = self.createImage(idNull, "Textures\\menu_divider.tga");
				}
				image->borderAllSides = 8;
				image->widthProportional = 1.0;
				image->flagExtendImageToBounds = 1;
				return image;
			};
			usertypeDefinition["createFillBar"] = [](Element& self, sol::optional<sol::table> args) {
				Element * element = nullptr;
				if (args) {
					element = self.createFillBar(args.value().get_or("id", idNull));
					auto fillbar = TES3::UI::WidgetFillbar::fromElement(element);
					fillbar->setCurrent(args.value().get_or("current", 0));
					fillbar->setMax(args.value().get_or("max", 0));
				}
				else {
					element = self.createFillBar(idNull);
					auto fillbar = TES3::UI::WidgetFillbar::fromElement(element);
					fillbar->setCurrent(0);
					fillbar->setMax(0);
				}
				return element;
			};
			usertypeDefinition["createHorizontalScrollPane"] = [](Element& self, sol::optional<sol::table> args) {
				Element * scrollpane = nullptr;
				if (args) {
					scrollpane = self.createHorizontalScrollPane(args.value().get_or("id", idNull));
				}
				else {
					scrollpane = self.createHorizontalScrollPane(idNull);
				}

				// Add mouse wheel handlers (see event dispatch patch in TES3UIManager.cpp)
				scrollpane->setProperty(TES3::UI::Property::event_mouse_scroll_down, TES3::UI::onScrollPaneMousewheel);
				scrollpane->setProperty(TES3::UI::Property::event_mouse_scroll_up, TES3::UI::onScrollPaneMousewheel);
				return scrollpane;
			};
			usertypeDefinition["createHypertext"] = [](Element& self, sol::optional<sol::table> args) {
				if (args) {
					return self.createHypertext(args.value().get_or("id", idNull));
				}
				else {
					return self.createHypertext(idNull);
				}
			};
			usertypeDefinition["createImage"] = [](Element& self, sol::table args) {
				auto path = args.get<sol::optional<const char*>>("path");
				if (path) {
					std::string pathStr = path.value();
					if (pathStr.find("/") != std::string::npos) {
						std::replace(pathStr.begin(), pathStr.end(), '/', '\\');
					}

					return self.createImage(args.get_or("id", idNull), pathStr.c_str());
				}
				else {
					log::getLog() << "createImage: path argument is required." << std::endl;
					logStackTrace();
				}
				return static_cast<Element*>(nullptr);
			};
			usertypeDefinition["createLabel"] = [](Element& self, sol::table args) {
				auto text = args.get<sol::optional<const char*>>("text");
				return self.createLabel(args.get_or("id", idNull), text.value_or("(nil)"));
			};
			usertypeDefinition["createNif"] = [](Element& self, sol::table args) {
				auto path = args.get<sol::optional<const char*>>("path");
				if (path) {
					std::string pathStr = path.value();
					if (pathStr.find("/") != std::string::npos) {
						std::replace(pathStr.begin(), pathStr.end(), '/', '\\');
					}

					return self.createNif(args.get_or("id", idNull), pathStr.c_str());
				}
				else {
					log::getLog() << "createNif: path argument is required." << std::endl;
					logStackTrace();
				}
				return static_cast<Element*>(nullptr);
			};
			usertypeDefinition["createParagraphInput"] = [](Element& self, sol::optional<sol::table> args) {
				if (args) {
					return self.createParagraphInput(args.value().get_or("id", idNull));
				}
				else {
					return self.createParagraphInput(idNull);
				}
			};
			usertypeDefinition["createRect"] = [](Element& self, sol::table args) {
				Element* rect = self.createRect(args.get_or("id", idNull));
				auto argColour = args.get<sol::optional<sol::table>>("color");
				if (argColour) {
					auto c = argColour.value();
					rect->colourRed = c[1];
					rect->colourGreen = c[2];
					rect->colourBlue = c[3];
					rect->flagUsesRGBA = 1;
				}
				return rect;
			};
			usertypeDefinition["createSlider"] = [](Element& self, sol::table args) {
				auto element = self.createSlider(args.get_or("id", idNull));
				auto slider = TES3::UI::WidgetScrollBar::fromElement(element);
				slider->setCurrent(args.get_or("current", 0));
				slider->setMax(args.get_or("max", 0));
				slider->setStepX(args.get_or("step", 1));
				slider->setJumpX(args.get_or("jump", 5));
				return element;
			};
			usertypeDefinition["createSliderVertical"] = [](Element& self, sol::table args) {
				auto element = self.createSliderVertical(args.get_or("id", idNull));
				auto slider = TES3::UI::WidgetScrollBar::fromElement(element);
				slider->setCurrent(args.get_or("current", 0));
				slider->setMax(args.get_or("max", 0));
				slider->setStepX(args.get_or("step", 1));
				slider->setJumpX(args.get_or("jump", 5));
				return element;
			};
			usertypeDefinition["createTextInput"] = [](Element& self, sol::optional<sol::table> args) {
				if (args) {
					return self.createTextInput(args.value().get_or("id", idNull));
				}
				else {
					return self.createTextInput(idNull);
				}
			};
			usertypeDefinition["createTextSelect"] = [](Element& self, sol::table args) {
				auto element = self.createTextSelect(args.get_or("id", idNull));
				auto text = args.get<sol::optional<const char*>>("text");
				if (text) {
					element->setText(text.value());
				}
				auto textSelect = TES3::UI::WidgetTextSelect::fromElement(element);
				auto state = args.get<sol::optional<int>>("state");
				if (state) {
					textSelect->setState(state.value());
				}
				return element;
			};
			usertypeDefinition["createThinBorder"] = [](Element& self, sol::optional<sol::table> args) {
				if (args) {
					return self.createNif(args.value().get_or("id", idNull), "menu_thin_border.nif");
				}
				else {
					return self.createNif(idNull, "menu_thin_border.nif");
				}
			};
			usertypeDefinition["createVerticalScrollPane"] = [](Element& self, sol::table args) {
				auto scrollpane = self.createVerticalScrollPane(args.get_or("id", idNull));

				if (args.get_or("hideFrame", false)) {
					scrollpane->setIcon("");
				}

				// Add mouse wheel handlers (see event dispatch patch in TES3UIManager.cpp)
				scrollpane->setProperty(TES3::UI::Property::event_mouse_scroll_down, TES3::UI::onScrollPaneMousewheel);
				scrollpane->setProperty(TES3::UI::Property::event_mouse_scroll_up, TES3::UI::onScrollPaneMousewheel);
				return scrollpane;
			};

			usertypeDefinition["destroy"] = [](Element& self) {
				UI_ID id = self.id;
				self.destroy();
				// Lua cleanup runs in destroy event handler
			};
		}
	}
}

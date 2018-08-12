#include "TES3UIManager.h"
#include "TES3UIWidgets.h"

#include "sol.hpp"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		using TES3::UI::Element;
		using TES3::UI::Property;
		using TES3::UI::PropertyType;
		using TES3::UI::WidgetButton;
		using TES3::UI::WidgetFillbar;
		using TES3::UI::WidgetScrollBar;
		using TES3::UI::WidgetTextInput;
		using TES3::UI::WidgetTextSelect;
		using TES3::UI::registerProperty;

		static Property propButton, propFillbar, propScrollBar, propTextInput, propTextSelect;

		void bindTES3UIWidgets();

		sol::object makeWidget(Element& element) {
			static bool deferredInit = false;
			if (!deferredInit) {
				propButton = registerProperty("PartButton");
				propFillbar = registerProperty("PartFillbar");
				propScrollBar = registerProperty("PartScrollBar");
				propTextInput = registerProperty("PartTextInput");
				propTextSelect = registerProperty("PartTextSelect");
				deferredInit = true;
			}

			sol::state& state = LuaManager::getInstance().getState();
			sol::object widget = sol::nil;
			Property part = element.getProperty(PropertyType::Property, Property::is_part).propertyValue;

			if (part == propButton) {
				widget = sol::make_object(state, WidgetButton::fromElement(&element));
			}
			else if (part == propFillbar) {
				widget = sol::make_object(state, WidgetFillbar::fromElement(&element));
			}
			else if (part == propScrollBar) {
				widget = sol::make_object(state, WidgetScrollBar::fromElement(&element));
			}
			else if (part == propTextInput) {
				widget = sol::make_object(state, WidgetTextInput::fromElement(&element));
			}
			else if (part == propTextSelect) {
				widget = sol::make_object(state, WidgetTextSelect::fromElement(&element));
			}
			return widget;
		}

		void bindTES3UIWidgets() {
			sol::state& state = LuaManager::getInstance().getState();

			//
			// Button (PartButton)
			//
			{
				auto usertypeDefinition = state.create_simple_usertype<WidgetButton>();
				usertypeDefinition.set("new", sol::no_constructor);

				usertypeDefinition.set("state", sol::property(&WidgetButton::getState, &WidgetButton::setState));
				usertypeDefinition.set("idle", sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourIdle({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("over", sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourOver({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("pressed", sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourPressed({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("idleDisabled", sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourDisabled({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("overDisabled", sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourDisabledOver({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("pressedDisabled", sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourDisabledPressed({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("idleActive", sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourActive({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("overActive", sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourActiveOver({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("pressedActive", sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourActivePressed({ c[1], c[2], c[3] }); }
				));

				state.set_usertype("tes3uiButton", usertypeDefinition);
			}

			//
			// FillBar (PartFillbar)
			//
			{
				auto usertypeDefinition = state.create_simple_usertype<WidgetFillbar>();
				usertypeDefinition.set("new", sol::no_constructor);

				usertypeDefinition.set("current", sol::property(&WidgetFillbar::getCurrent, &WidgetFillbar::setCurrent));
				usertypeDefinition.set("max", sol::property(&WidgetFillbar::getMax, &WidgetFillbar::setMax));
				usertypeDefinition.set("showText", sol::property(&WidgetFillbar::getShowText, &WidgetFillbar::setShowText));
				usertypeDefinition.set("fillColor", sol::property(
					[](WidgetFillbar& self, sol::table c) { self.setFillColour({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("fillAlpha", sol::property(&WidgetFillbar::setFillAlpha));

				state.set_usertype("tes3uiFillBar", usertypeDefinition);
			}

			//
			// Slider (PartScrollBar)
			//
			{
				auto usertypeDefinition = state.create_simple_usertype<WidgetScrollBar>();
				usertypeDefinition.set("new", sol::no_constructor);

				usertypeDefinition.set("current", sol::property(&WidgetScrollBar::getCurrent, &WidgetScrollBar::setCurrent));
				usertypeDefinition.set("max", sol::property(&WidgetScrollBar::getMax, &WidgetScrollBar::setMax));
				usertypeDefinition.set("step", sol::property(&WidgetScrollBar::getStepX, &WidgetScrollBar::setStepX));
				usertypeDefinition.set("jump", sol::property(&WidgetScrollBar::getJumpX, &WidgetScrollBar::setJumpX));

				state.set_usertype("tes3uiSlider", usertypeDefinition);
			}

			//
			// TextInput (PartTextInput)
			//
			{
				auto usertypeDefinition = state.create_simple_usertype<WidgetTextInput>();
				usertypeDefinition.set("new", sol::no_constructor);

				usertypeDefinition.set("lengthLimit", sol::property(
					[](WidgetTextInput& self) {
						sol::optional<int> limit;

						// Convert no limit to nil
						int n = self.getLengthLimit();
						if (!self.getNoLimit() && n > 0) {
							limit = n;
						}
						return limit;
					},
					[](WidgetTextInput& self, sol::optional<int> limit) {
						// Convert nil to no limit
						if (limit) {
							self.setLengthLimit(limit.value());
							self.setNoLimit(false);
						}
						else {
							self.setNoLimit(true);
						}
					}
				));
				usertypeDefinition.set("eraseOnFirstKey", sol::property(&WidgetTextInput::getEraseOnFirstKey, &WidgetTextInput::setEraseOnFirstKey));

				state.set_usertype("tes3uiTextInput", usertypeDefinition);
			}

			//
			// TextSelect (PartTextSelect)
			//
			{
				auto usertypeDefinition = state.create_simple_usertype<WidgetTextSelect>();
				usertypeDefinition.set("new", sol::no_constructor);

				usertypeDefinition.set("state", sol::property(&WidgetTextSelect::getState, &WidgetTextSelect::setState));
				usertypeDefinition.set("idle", sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourIdle({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("over", sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourOver({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("pressed", sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourPressed({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("idleDisabled", sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourDisabled({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("overDisabled", sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourDisabledOver({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("pressedDisabled", sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourDisabledPressed({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("idleActive", sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourActive({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("overActive", sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourActiveOver({ c[1], c[2], c[3] }); }
				));
				usertypeDefinition.set("pressedActive", sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourActivePressed({ c[1], c[2], c[3] }); }
				));

				state.set_usertype("tes3uiTextSelect", usertypeDefinition);
			}
		}

	}
}
#include "TES3UIManager.h"
#include "TES3UIWidgets.h"

#include "sol.hpp"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		using TES3::UI::Element;
		using TES3::UI::Property;
		using TES3::UI::PropertyType;
		using TES3::UI::UI_ID;
		using TES3::UI::WidgetButton;
		using TES3::UI::WidgetFillbar;
		using TES3::UI::WidgetParagraphInput;
		using TES3::UI::WidgetScrollBar;
		using TES3::UI::WidgetScrollPane;
		using TES3::UI::WidgetTextInput;
		using TES3::UI::WidgetTextSelect;
		using TES3::UI::registerID;
		using TES3::UI::registerProperty;

		static Property propButton, propFillbar, propParagraphInput;
		static Property propScrollBar, propScrollPaneH, propScrollPaneV;
		static Property propTextInput, propTextSelect;
		static UI_ID uiidButtonText, uiidParagraphInputText;

		void bindTES3UIWidgets();

		void deferredPropInit() {
			static bool init = false;
			if (!init) {
				propButton = registerProperty("PartButton");
				propFillbar = registerProperty("PartFillbar");
				propParagraphInput = registerProperty("PartParagraphInput");
				propScrollBar = registerProperty("PartScrollBar");
				propScrollPaneH = registerProperty("PartScrollPaneHor");
				propScrollPaneV = registerProperty("PartScrollPaneVert");
				propTextInput = registerProperty("PartTextInput");
				propTextSelect = registerProperty("PartTextSelect");
				uiidButtonText = registerID("PartButton_text_ptr");
				uiidParagraphInputText = registerID("PartParagraphInput_text_input");
				init = true;
			}
		}

		sol::object makeWidget(Element& element) {
			deferredPropInit();

			sol::state& state = LuaManager::getInstance().getState();
			sol::object widget = sol::nil;
			Property part = element.getProperty(PropertyType::Property, Property::is_part).propertyValue;

			if (part == propButton) {
				widget = sol::make_object(state, WidgetButton::fromElement(&element));
			}
			else if (part == propFillbar) {
				widget = sol::make_object(state, WidgetFillbar::fromElement(&element));
			}
			else if (part == propParagraphInput) {
				widget = sol::make_object(state, WidgetParagraphInput::fromElement(&element));
			}
			else if (part == propScrollBar) {
				widget = sol::make_object(state, WidgetScrollBar::fromElement(&element));
			}
			else if (part == propScrollPaneH || part == propScrollPaneV) {
				widget = sol::make_object(state, WidgetScrollPane::fromElement(&element));
			}
			else if (part == propTextInput) {
				widget = sol::make_object(state, WidgetTextInput::fromElement(&element));
			}
			else if (part == propTextSelect) {
				widget = sol::make_object(state, WidgetTextSelect::fromElement(&element));
			}
			return widget;
		}

		std::string getWidgetText(Element& element) {
			deferredPropInit();

			Property part = element.getProperty(PropertyType::Property, Property::is_part).propertyValue;

			if (part == propButton) {
				return WidgetButton::fromElement(&element)->getText();
			}
			else if (part == propParagraphInput) {
				return WidgetParagraphInput::fromElement(&element)->getText();
			}
			else if (part == propTextInput) {
				return WidgetTextInput::fromElement(&element)->getText();
			}
			else {
				return element.getText();
			}
		}

		void setWidgetText(Element& element, const char* text) {
			deferredPropInit();

			Property part = element.getProperty(PropertyType::Property, Property::is_part).propertyValue;

			if (part == propButton) {
				WidgetButton::fromElement(&element)->setText(text);
			}
			else if (part == propParagraphInput) {
				WidgetParagraphInput::fromElement(&element)->setText(text);
			}
			else if (part == propTextInput) {
				WidgetTextInput::fromElement(&element)->setText(text);
			}
			else {
				element.setText(text);
			}

			element.getTopLevelParent()->timingUpdate();
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
			// ParagraphInput (PartParagraphInput)
			//
			{
				auto usertypeDefinition = state.create_simple_usertype<WidgetParagraphInput>();
				usertypeDefinition.set("new", sol::no_constructor);

				usertypeDefinition.set("lengthLimit", sol::property(
					[](WidgetParagraphInput& self) { return self.getLengthLimit(); },
					[](WidgetParagraphInput& self, sol::optional<int> limit) {
						const int defaultLength = 0x3ff;
						self.setLengthLimit(limit.value_or(defaultLength));
					}
				));

				state.set_usertype("tes3uiParagraphInput", usertypeDefinition);
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
			// ScrollPane (PartScrollPane)
			//
			{
				auto usertypeDefinition = state.create_simple_usertype<WidgetScrollPane>();
				usertypeDefinition.set("new", sol::no_constructor);

				usertypeDefinition.set("contentsChanged", &WidgetScrollPane::contentPaneChanged);
				usertypeDefinition.set("positionX", sol::property(&WidgetScrollPane::getHorizontalPos, &WidgetScrollPane::setHorizontalPos));
				usertypeDefinition.set("positionY", sol::property(&WidgetScrollPane::getVerticalPos, &WidgetScrollPane::setVerticalPos));
				usertypeDefinition.set("scrollbarVisible", sol::property(&WidgetScrollPane::getScrollbarVisible, &WidgetScrollPane::setScrollbarVisible));

				// Quick access to the pane contents.
				usertypeDefinition.set("contentPane", sol::readonly_property(&WidgetScrollPane::getContentPane));

				state.set_usertype("tes3uiScrollPane", usertypeDefinition);
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
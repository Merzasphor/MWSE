#include "TES3UIManager.h"
#include "TES3UIWidgets.h"

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

			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;
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
			if (text == nullptr) {
				text = "";
			}

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
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			//
			// Button (PartButton)
			//
			{
				auto usertypeDefinition = state.new_usertype<WidgetButton>("tes3uiButton");
				usertypeDefinition["new"] = sol::no_constructor;

				usertypeDefinition["state"] = sol::property(&WidgetButton::getState, &WidgetButton::setState);
				usertypeDefinition["idle"] = sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourIdle({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["over"] = sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourOver({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["pressed"] = sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourPressed({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["idleDisabled"] = sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourDisabled({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["overDisabled"] = sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourDisabledOver({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["pressedDisabled"] = sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourDisabledPressed({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["idleActive"] = sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourActive({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["overActive"] = sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourActiveOver({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["pressedActive"] = sol::property(
					[](WidgetButton& self, sol::table c) { self.setColourActivePressed({ c[1], c[2], c[3] }); }
				);

				
			}

			//
			// FillBar (PartFillbar)
			//
			{
				auto usertypeDefinition = state.new_usertype<WidgetFillbar>("tes3uiFillBar");
				usertypeDefinition["new"] = sol::no_constructor;

				usertypeDefinition["current"] = sol::property(&WidgetFillbar::getCurrent, &WidgetFillbar::setCurrent);
				usertypeDefinition["max"] = sol::property(&WidgetFillbar::getMax, &WidgetFillbar::setMax);
				usertypeDefinition["showText"] = sol::property(&WidgetFillbar::getShowText, &WidgetFillbar::setShowText);
				usertypeDefinition["normalized"] = sol::property(&WidgetFillbar::getNormalized, &WidgetFillbar::setNormalized);
				usertypeDefinition["fillColor"] = sol::property(
					[](WidgetFillbar& self, sol::table c) { self.setFillColour({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["fillAlpha"] = sol::property(&WidgetFillbar::setFillAlpha);

				
			}

			//
			// ParagraphInput (PartParagraphInput)
			//
			{
				auto usertypeDefinition = state.new_usertype<WidgetParagraphInput>("tes3uiParagraphInput");
				usertypeDefinition["new"] = sol::no_constructor;

				usertypeDefinition["lengthLimit"] = sol::property(
					[](WidgetParagraphInput& self) { return self.getLengthLimit(); },
					[](WidgetParagraphInput& self, sol::optional<int> limit) {
						const int defaultLength = 0x3ff;
						self.setLengthLimit(limit.value_or(defaultLength));
					}
				);

				
			}

			//
			// Slider (PartScrollBar)
			//
			{
				auto usertypeDefinition = state.new_usertype<WidgetScrollBar>("tes3uiSlider");
				usertypeDefinition["new"] = sol::no_constructor;

				usertypeDefinition["current"] = sol::property(&WidgetScrollBar::getCurrent, &WidgetScrollBar::setCurrent);
				usertypeDefinition["max"] = sol::property(&WidgetScrollBar::getMax, &WidgetScrollBar::setMax);
				usertypeDefinition["step"] = sol::property(&WidgetScrollBar::getStepX, &WidgetScrollBar::setStepX);
				usertypeDefinition["jump"] = sol::property(&WidgetScrollBar::getJumpX, &WidgetScrollBar::setJumpX);

				
			}

			//
			// ScrollPane (PartScrollPane)
			//
			{
				auto usertypeDefinition = state.new_usertype<WidgetScrollPane>("tes3uiScrollPane");
				usertypeDefinition["new"] = sol::no_constructor;

				usertypeDefinition["contentsChanged"] = &WidgetScrollPane::contentPaneChanged;
				usertypeDefinition["positionX"] = sol::property(&WidgetScrollPane::getHorizontalPos, &WidgetScrollPane::setHorizontalPos);
				usertypeDefinition["positionY"] = sol::property(&WidgetScrollPane::getVerticalPos, &WidgetScrollPane::setVerticalPos);
				usertypeDefinition["scrollbarVisible"] = sol::property(&WidgetScrollPane::getScrollbarVisible, &WidgetScrollPane::setScrollbarVisible);

				// Quick access to the pane contents.
				usertypeDefinition["contentPane"] = sol::readonly_property(&WidgetScrollPane::getContentPane);

				
			}

			//
			// TextInput (PartTextInput)
			//
			{
				auto usertypeDefinition = state.new_usertype<WidgetTextInput>("tes3uiTextInput");
				usertypeDefinition["new"] = sol::no_constructor;

				usertypeDefinition["lengthLimit"] = sol::property(
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
				);
				usertypeDefinition["eraseOnFirstKey"] = sol::property(&WidgetTextInput::getEraseOnFirstKey, &WidgetTextInput::setEraseOnFirstKey);

				
			}

			//
			// TextSelect (PartTextSelect)
			//
			{
				auto usertypeDefinition = state.new_usertype<WidgetTextSelect>("tes3uiTextSelect");
				usertypeDefinition["new"] = sol::no_constructor;

				usertypeDefinition["state"] = sol::property(&WidgetTextSelect::getState, &WidgetTextSelect::setState);
				usertypeDefinition["idle"] = sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourIdle({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["over"] = sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourOver({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["pressed"] = sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourPressed({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["idleDisabled"] = sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourDisabled({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["overDisabled"] = sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourDisabledOver({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["pressedDisabled"] = sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourDisabledPressed({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["idleActive"] = sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourActive({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["overActive"] = sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourActiveOver({ c[1], c[2], c[3] }); }
				);
				usertypeDefinition["pressedActive"] = sol::property(
					[](WidgetTextSelect& self, sol::table c) { self.setColourActivePressed({ c[1], c[2], c[3] }); }
				);

				
			}
		}

	}
}
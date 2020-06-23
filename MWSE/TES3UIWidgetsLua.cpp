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
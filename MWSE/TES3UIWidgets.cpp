#include <string>

#include "TES3UIManager.h"
#include "TES3UIWidgets.h"


namespace TES3 {
	namespace UI {
		static void initColourProperty(Property(&prop)[4], const char *prefix) {
			std::string name(prefix);
			std::string::size_type n = name.size();
			name.reserve(n + 6);

			name.replace(name.begin() + n, name.end(), "_red");
			prop[0] = registerProperty(name.c_str());
			name.replace(name.begin() + n, name.end(), "_green");
			prop[1] = registerProperty(name.c_str());
			name.replace(name.begin() + n, name.end(), "_blue");
			prop[2] = registerProperty(name.c_str());
			name.replace(name.begin() + n, name.end(), "_alpha");
			prop[3] = registerProperty(name.c_str());
		}

		//
		// WidgetFillbar
		//
		static Property propFillbarCurrent, propFillbarMax;
		static Property propFillbarShowText;
		static Property propFillbarCol[4];

		bool WidgetFillbar::initProperties() {
			propFillbarCurrent = registerProperty("PartFillbar_current");
			propFillbarMax = registerProperty("PartFillbar_max");
			propFillbarShowText = registerProperty("PartFillbar_show_text");
			initColourProperty(propFillbarCol, "PartFillbar");
			return true;
		}

		WidgetFillbar* WidgetFillbar::fromElement(Element* element) {
			static bool initialized = initProperties();
			return static_cast<WidgetFillbar*>(element);
		}

		int WidgetFillbar::getCurrent() const {
			return getProperty(PropertyType::Integer, propFillbarCurrent).integerValue;
		}
		void WidgetFillbar::setCurrent(int value) {
			setProperty(propFillbarCurrent, value);
		}

		int WidgetFillbar::getMax() const {
			return getProperty(PropertyType::Integer, propFillbarMax).integerValue;
		}
		void WidgetFillbar::setMax(int value) {
			setProperty(propFillbarMax, value);
		}

		bool WidgetFillbar::getShowText() const {
			auto prop = getProperty(PropertyType::Property, propFillbarShowText).propertyValue;
			return (prop == Property::boolean_true);
		}
		void WidgetFillbar::setShowText(bool flag) {
			auto value = flag ? Property::boolean_true : Property::boolean_false;
			setProperty(propFillbarShowText, value);
		}

		void WidgetFillbar::setFillColour(const float(&c)[3]) {
			setProperty(propFillbarCol[0], c[0]);
			setProperty(propFillbarCol[1], c[1]);
			setProperty(propFillbarCol[2], c[2]);
		}
		void WidgetFillbar::setFillAlpha(float a) {
			setProperty(propFillbarCol[3], a);
		}

		//
		// WidgetScrollBar
		//
		static Property propScrollBarCurrent, propScrollBarMax;
		static Property propScrollStepX, propScrollJumpX;

		bool WidgetScrollBar::initProperties() {
			propScrollBarCurrent = registerProperty("PartScrollBar_current");
			propScrollBarMax = registerProperty("PartScrollBar_max");
			propScrollStepX = registerProperty("PartScrollBar_step_x");
			propScrollJumpX = registerProperty("PartScrollBar_jump_x");
			return true;
		}

		WidgetScrollBar* WidgetScrollBar::fromElement(Element* element) {
			static bool initialized = initProperties();
			return static_cast<WidgetScrollBar*>(element);
		}

		int WidgetScrollBar::getCurrent() const {
			return getProperty(PropertyType::Integer, propScrollBarCurrent).integerValue;
		}
		void WidgetScrollBar::setCurrent(int value) {
			setProperty(propScrollBarCurrent, value);
		}

		int WidgetScrollBar::getMax() const {
			return getProperty(PropertyType::Integer, propScrollBarMax).integerValue;
		}
		void WidgetScrollBar::setMax(int value) {
			setProperty(propScrollBarMax, value);
		}

		int WidgetScrollBar::getStepX() const {
			return getProperty(PropertyType::Integer, propScrollStepX).integerValue;
		}
		void WidgetScrollBar::setStepX(int value) {
			setProperty(propScrollStepX, value);
		}

		int WidgetScrollBar::getJumpX() const {
			return getProperty(PropertyType::Integer, propScrollJumpX).integerValue;
		}
		void WidgetScrollBar::setJumpX(int value) {
			setProperty(propScrollJumpX, value);
		}

		//
		// WidgetTextInput
		//
		static Property propTextInputLengthLimit, propTextInputNoLimit;
		static Property propTextInputEraseOnFirstKey;

		bool WidgetTextInput::initProperties() {
			propTextInputLengthLimit = registerProperty("PartTextInput_length_limit");
			propTextInputNoLimit = registerProperty("PartTextInput_no_limit");
			propTextInputEraseOnFirstKey = registerProperty("PartTextInput_erase_on_first_key");
			return true;
		}

		WidgetTextInput* WidgetTextInput::fromElement(Element* element) {
			static bool initialized = initProperties();
			return static_cast<WidgetTextInput*>(element);
		}

		int WidgetTextInput::getLengthLimit() const {
			return getProperty(PropertyType::Integer, propTextInputLengthLimit).integerValue;
		}
		void WidgetTextInput::setLengthLimit(int limit) {
			setProperty(propTextInputLengthLimit, limit);
		}

		bool WidgetTextInput::getNoLimit() const {
			auto prop = getProperty(PropertyType::Property, propTextInputNoLimit).propertyValue;
			return (prop == Property::boolean_true);
		}
		void WidgetTextInput::setNoLimit(bool flag) {
			auto value = flag ? Property::boolean_true : Property::boolean_false;
			setProperty(propTextInputNoLimit, value);
		}

		bool WidgetTextInput::getEraseOnFirstKey() const {
			auto prop = getProperty(PropertyType::Property, propTextInputEraseOnFirstKey).propertyValue;
			return (prop == Property::boolean_true);
		}
		void WidgetTextInput::setEraseOnFirstKey(bool flag) {
			auto value = flag ? Property::boolean_true : Property::boolean_false;
			setProperty(propTextInputEraseOnFirstKey, value);
		}

		//
		// WidgetTextSelect
		//
		static Property propSelectState;
		static Property propSelectIdle[4], propSelectOver[4], propSelectPressed[4];
		static Property propSelectDisabled[4], propSelectDisabledOver[4], propSelectDisabledPressed[4];
		static Property propSelectActive[4], propSelectActiveOver[4], propSelectActivePressed[4];

		bool WidgetTextSelect::initProperties() {
			propSelectState = registerProperty("PartTextSelect_state");
			initColourProperty(propSelectIdle, "PartTextSelect_idle");
			initColourProperty(propSelectOver, "PartTextSelect_over");
			initColourProperty(propSelectPressed, "PartTextSelect_pressed");
			initColourProperty(propSelectDisabled, "PartTextSelect_disabled");
			initColourProperty(propSelectDisabledOver, "PartTextSelect_disabled_over");
			initColourProperty(propSelectDisabledPressed, "PartTextSelect_disabled_pressed");
			initColourProperty(propSelectActive, "PartTextSelect_active");
			initColourProperty(propSelectActiveOver, "PartTextSelect_active_over");
			initColourProperty(propSelectActivePressed, "PartTextSelect_active_pressed");
			return true;
		}

		WidgetTextSelect* WidgetTextSelect::fromElement(Element* element) {
			static bool initialized = initProperties();
			return static_cast<WidgetTextSelect*>(element);
		}

		int WidgetTextSelect::getState() const {
			return getProperty(PropertyType::Integer, propSelectState).integerValue;
		}
		void WidgetTextSelect::setState(int state) {
			setProperty(propSelectState, state);
		}

		void WidgetTextSelect::setColourIdle(const float(&c)[3]) {
			setProperty(propSelectIdle[0], c[0]);
			setProperty(propSelectIdle[1], c[1]);
			setProperty(propSelectIdle[2], c[2]);
		}

		void WidgetTextSelect::setColourOver(const float(&c)[3]) {
			setProperty(propSelectIdle[0], c[0]);
			setProperty(propSelectIdle[1], c[1]);
			setProperty(propSelectIdle[2], c[2]);
		}

		void WidgetTextSelect::setColourPressed(const float(&c)[3]) {
			setProperty(propSelectIdle[0], c[0]);
			setProperty(propSelectIdle[1], c[1]);
			setProperty(propSelectIdle[2], c[2]);
		}

		void WidgetTextSelect::setColourDisabled(const float(&c)[3]) {
			setProperty(propSelectIdle[0], c[0]);
			setProperty(propSelectIdle[1], c[1]);
			setProperty(propSelectIdle[2], c[2]);
		}

		void WidgetTextSelect::setColourDisabledOver(const float(&c)[3]) {
			setProperty(propSelectIdle[0], c[0]);
			setProperty(propSelectIdle[1], c[1]);
			setProperty(propSelectIdle[2], c[2]);
		}

		void WidgetTextSelect::setColourDisabledPressed(const float(&c)[3]) {
			setProperty(propSelectIdle[0], c[0]);
			setProperty(propSelectIdle[1], c[1]);
			setProperty(propSelectIdle[2], c[2]);
		}

		void WidgetTextSelect::setColourActive(const float(&c)[3]) {
			setProperty(propSelectIdle[0], c[0]);
			setProperty(propSelectIdle[1], c[1]);
			setProperty(propSelectIdle[2], c[2]);
		}

		void WidgetTextSelect::setColourActiveOver(const float(&c)[3]) {
			setProperty(propSelectIdle[0], c[0]);
			setProperty(propSelectIdle[1], c[1]);
			setProperty(propSelectIdle[2], c[2]);
		}

		void WidgetTextSelect::setColourActivePressed(const float(&c)[3]) {
			setProperty(propSelectIdle[0], c[0]);
			setProperty(propSelectIdle[1], c[1]);
			setProperty(propSelectIdle[2], c[2]);
		}

	}
}
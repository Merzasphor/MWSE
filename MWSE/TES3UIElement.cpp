#include "TES3UIManager.h"
#include "TES3UIElement.h"

namespace TES3 {
	namespace UI {
		typedef Element* (__cdecl *TES3_UI_WidgetFactoryMethod_t)(Element*);

		const auto TES3_ui_createBlock = reinterpret_cast<Element* (__thiscall *)(Element*, UI_ID, Boolean)>(0x588980);
		const auto TES3_ui_createImage = reinterpret_cast<Element* (__thiscall *)(Element*, UI_ID, const char*, Boolean)>(0x588630);
		const auto TES3_ui_createLabel = reinterpret_cast<Element* (__thiscall *)(Element*, UI_ID, const char*, Boolean, Boolean)>(0x588BE0);
		const auto TES3_ui_createWidget = reinterpret_cast<Element* (__thiscall *)(Element*, UI_ID, TES3_UI_WidgetFactoryMethod_t, Boolean)>(0x588140);
		const auto TES3_ui_loadNif = reinterpret_cast<Element* (__thiscall *)(Element*, UI_ID, const char*, Boolean)>(0x588830);
		const auto TES3_deleting_dtor_UIElement = reinterpret_cast<void (__thiscall *)(Element*, char)>(0x578880);
		const auto TES3_ui_factoryButton = reinterpret_cast<TES3_UI_WidgetFactoryMethod_t>(0x639420);
		const auto TES3_ui_factoryDragFrame = reinterpret_cast<TES3_UI_WidgetFactoryMethod_t>(0x63B5E0);
		const auto TES3_ui_factoryFillBar = reinterpret_cast<TES3_UI_WidgetFactoryMethod_t>(0x63E640);
		const auto TES3_ui_factoryFixedFrame = reinterpret_cast<TES3_UI_WidgetFactoryMethod_t>(0x642550);
		const auto TES3_ui_factoryHorzScrollPane = reinterpret_cast<TES3_UI_WidgetFactoryMethod_t>(0x648C10);
		const auto TES3_ui_factoryHypertext = reinterpret_cast<TES3_UI_WidgetFactoryMethod_t>(0x640970);
		const auto TES3_ui_factoryParagraphInput = reinterpret_cast<TES3_UI_WidgetFactoryMethod_t>(0x643130);
		const auto TES3_ui_factorySlider = reinterpret_cast<TES3_UI_WidgetFactoryMethod_t>(0x645EB0);
		const auto TES3_ui_factorySliderVert = reinterpret_cast<TES3_UI_WidgetFactoryMethod_t>(0x646670);
		const auto TES3_ui_factoryTextInput = reinterpret_cast<TES3_UI_WidgetFactoryMethod_t>(0x64A8E0);
		const auto TES3_ui_factoryTextSelect = reinterpret_cast<TES3_UI_WidgetFactoryMethod_t>(0x64C180);
		const auto TES3_ui_factoryVertScrollPane = reinterpret_cast<TES3_UI_WidgetFactoryMethod_t>(0x648FD0);

		const auto TES3_ui_findChildElement = reinterpret_cast<Element* (__thiscall *)(Element*, UI_ID)>(0x582DE0);
		const auto TES3_ui_performLayout = reinterpret_cast<Element* (__thiscall *)(Element*, Boolean)>(0x583B70);
		const auto TES3_ui_setAutoHeight = reinterpret_cast<void (__thiscall *)(Element*, Boolean)>(0x581400);
		const auto TES3_ui_setAutoWidth = reinterpret_cast<void (__thiscall *)(Element*, Boolean)>(0x5813C0);
		const auto TES3_ui_setVisible = reinterpret_cast<void (__thiscall *)(Element*, Boolean)>(0x57F2A0);
		const auto TES3_ui_timingUpdate = reinterpret_cast<long (__thiscall *)(Element*)>(0x583B60);

		const auto TES3_ui_getProperty = reinterpret_cast<void (__thiscall *)(const Element*, PropertyValue*, Property, PropertyType, const Element*, Boolean)>(0x581440);
		const auto TES3_ui_getText = reinterpret_cast<const char* (__thiscall *)(const Element*)>(0x580BB0);
		const auto TES3_ui_setProperty = reinterpret_cast<void (__thiscall *)(Element*, Property, PropertyValue, PropertyType)>(0x581F30);
		const auto TES3_ui_setText = reinterpret_cast<void (__thiscall *)(Element*, const char*)>(0x58AD30);

		//
		// Widget creation/destruction methods
		//

		Element* Element::createBlock(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createBlock(this, id, bReplaceThisElement);
		}

		Element* Element::createButton(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryButton, bReplaceThisElement);
		}

		Element* Element::createDragFrame(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryDragFrame, bReplaceThisElement);
		}

		Element* Element::createFillBar(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryFillBar, bReplaceThisElement);
		}

		Element* Element::createFixedFrame(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryFixedFrame, bReplaceThisElement);
		}

		Element* Element::createHorizontalScrollPane(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryHorzScrollPane, bReplaceThisElement);
		}

		Element* Element::createHypertext(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryHypertext, bReplaceThisElement);
		}

		Element* Element::createImage(UI_ID id, const char* imagePath, Boolean bReplaceThisElement) {
			return TES3_ui_createImage(this, id, imagePath, bReplaceThisElement);
		}

		Element* Element::createLabel(UI_ID id, const char* text, Boolean bBlackText, Boolean bReplaceThisElement) {
			return TES3_ui_createLabel(this, id, text, bBlackText, bReplaceThisElement);
		}

		Element* Element::createNif(UI_ID id, const char* path, Boolean bReplaceThisElement) {
			return TES3_ui_loadNif(this, id, path, bReplaceThisElement);
		}

		Element* Element::createParagraphInput(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryParagraphInput, bReplaceThisElement);
		}

		Element* Element::createSlider(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createWidget(this, id, TES3_ui_factorySlider, bReplaceThisElement);
		}

		Element* Element::createSliderVertical(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createWidget(this, id, TES3_ui_factorySliderVert, bReplaceThisElement);
		}

		Element* Element::createTextInput(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryTextInput, bReplaceThisElement);
		}

		Element* Element::createTextSelect(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryTextSelect, bReplaceThisElement);
		}

		Element* Element::createVerticalScrollPane(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryVertScrollPane, bReplaceThisElement);
		}

		void Element::destroy() {
			TES3_deleting_dtor_UIElement(this, 1);
		}

		//
		// Layout methods
		//

		Element* Element::findChild(UI_ID id) {
			return TES3_ui_findChildElement(this, id);
		}

		Element* Element::performLayout(Boolean bUpdateTimestamp) {
			return TES3_ui_performLayout(this, bUpdateTimestamp);
		}

		void Element::setAutoHeight(Boolean bAuto) {
			return TES3_ui_setAutoHeight(this, bAuto);
		}

		void Element::setAutoWidth(Boolean bAuto) {
			return TES3_ui_setAutoWidth(this, bAuto);
		}

		void Element::setVisible(Boolean bVisible) {
			return TES3_ui_setVisible(this, bVisible);
		}

		long Element::timingUpdate() {
			return TES3_ui_timingUpdate(this);
		}

		//
		// Property methods
		//

		PropertyValue Element::getProperty(PropertyType propType, Property prop) const {
			PropertyValue v;
			TES3_ui_getProperty(this, &v, prop, propType, nullptr, 0);
			return v;
		}

		void Element::setProperty(Property prop, int value) {
			PropertyValue v;
			v.integerValue = value;
			TES3_ui_setProperty(this, prop, v, PropertyType::Integer);
		}

		void Element::setProperty(Property prop, float value) {
			PropertyValue v;
			v.floatValue = value;
			TES3_ui_setProperty(this, prop, v, PropertyType::Float);
		}

		void Element::setProperty(Property prop, void* value) {
			PropertyValue v;
			v.ptrValue = value;
			TES3_ui_setProperty(this, prop, v, PropertyType::Pointer);
		}

		void Element::setProperty(Property prop, Property value) {
			PropertyValue v;
			v.propertyValue = value;
			TES3_ui_setProperty(this, prop, v, PropertyType::Property);
		}

		void Element::setProperty(Property prop, EventCallback value) {
			PropertyValue v;
			v.eventCallback = value;
			TES3_ui_setProperty(this, prop, v, PropertyType::EventCallback);
		}

		void Element::setProperty(Property prop, PropertyAccessCallback value) {
			PropertyValue v;
			v.propertyCallback = value;
			TES3_ui_setProperty(this, prop, v, PropertyType::PropertyAccessCallback);
		}

		const char* Element::getText() const {
			return TES3_ui_getText(this);
		}

		void Element::setText(const char* text) {
			TES3_ui_setText(this, text);
		}

	}
}

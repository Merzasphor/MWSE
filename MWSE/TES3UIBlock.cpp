#include "TES3UIManager.h"
#include "TES3UIBlock.h"

namespace TES3 {
	namespace UI {
		typedef Block* (__cdecl *TES3_UI_WidgetFactoryMethod_t)(Block*);

		const auto TES3_ui_createBlock = reinterpret_cast<Block* (__thiscall *)(Block*, UI_ID, Boolean)>(0x588980);
		const auto TES3_ui_createImage = reinterpret_cast<Block* (__thiscall *)(Block*, UI_ID, const char*, Boolean)>(0x588630);
		const auto TES3_ui_createLabel = reinterpret_cast<Block* (__thiscall *)(Block*, UI_ID, const char*, Boolean, Boolean)>(0x588BE0);
		const auto TES3_ui_createWidget = reinterpret_cast<Block* (__thiscall *)(Block*, UI_ID, TES3_UI_WidgetFactoryMethod_t, Boolean)>(0x588140);
		const auto TES3_ui_loadNif = reinterpret_cast<Block* (__thiscall *)(Block*, UI_ID, const char*, Boolean)>(0x588830);
		const auto TES3_deleting_dtor_UIBlock = reinterpret_cast<void (__thiscall *)(Block*, char)>(0x578880);
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

		const auto TES3_ui_findChildBlock = reinterpret_cast<Block* (__thiscall *)(Block*, UI_ID)>(0x582DE0);
		const auto TES3_ui_performLayout = reinterpret_cast<Block* (__thiscall *)(Block*, Boolean)>(0x583B70);
		const auto TES3_ui_setAutoHeight = reinterpret_cast<void (__thiscall *)(Block*, Boolean)>(0x581400);
		const auto TES3_ui_setAutoWidth = reinterpret_cast<void (__thiscall *)(Block*, Boolean)>(0x5813C0);
		const auto TES3_ui_setVisible = reinterpret_cast<void (__thiscall *)(Block*, Boolean)>(0x57F2A0);
		const auto TES3_ui_timingUpdate = reinterpret_cast<long (__thiscall *)(Block*)>(0x583B60);

		const auto TES3_ui_getProperty = reinterpret_cast<void (__thiscall *)(const Block*, PropertyValue*, Property, PropertyType, const Block*, Boolean)>(0x581440);
		const auto TES3_ui_getText = reinterpret_cast<const char* (__thiscall *)(const Block*)>(0x580BB0);
		const auto TES3_ui_setProperty = reinterpret_cast<void (__thiscall *)(Block*, Property, PropertyValue, PropertyType)>(0x581F30);
		const auto TES3_ui_setText = reinterpret_cast<void (__thiscall *)(Block*, const char*)>(0x58AD30);

		//
		// Widget creation/destruction methods
		//

		Block* Block::createBlock(UI_ID id, Boolean bReplaceThisBlock) {
			return TES3_ui_createBlock(this, id, bReplaceThisBlock);
		}

		Block* Block::createButton(UI_ID id, Boolean bReplaceThisBlock) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryButton, bReplaceThisBlock);
		}

		Block* Block::createDragFrame(UI_ID id, Boolean bReplaceThisBlock) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryDragFrame, bReplaceThisBlock);
		}

		Block* Block::createFillBar(UI_ID id, Boolean bReplaceThisBlock) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryFillBar, bReplaceThisBlock);
		}

		Block* Block::createFixedFrame(UI_ID id, Boolean bReplaceThisBlock) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryFixedFrame, bReplaceThisBlock);
		}

		Block* Block::createHorizontalScrollPane(UI_ID id, Boolean bReplaceThisBlock) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryHorzScrollPane, bReplaceThisBlock);
		}

		Block* Block::createHypertext(UI_ID id, Boolean bReplaceThisBlock) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryHypertext, bReplaceThisBlock);
		}

		Block* Block::createImage(UI_ID id, const char* imagePath, Boolean bReplaceThisBlock) {
			return TES3_ui_createImage(this, id, imagePath, bReplaceThisBlock);
		}

		Block* Block::createLabel(UI_ID id, const char* text, Boolean bBlackText, Boolean bReplaceThisBlock) {
			return TES3_ui_createLabel(this, id, text, bBlackText, bReplaceThisBlock);
		}

		Block* Block::createNif(UI_ID id, const char* path, Boolean bReplaceThisBlock) {
			return TES3_ui_loadNif(this, id, path, bReplaceThisBlock);
		}

		Block* Block::createParagraphInput(UI_ID id, Boolean bReplaceThisBlock) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryParagraphInput, bReplaceThisBlock);
		}

		Block* Block::createSlider(UI_ID id, Boolean bReplaceThisBlock) {
			return TES3_ui_createWidget(this, id, TES3_ui_factorySlider, bReplaceThisBlock);
		}

		Block* Block::createSliderVertical(UI_ID id, Boolean bReplaceThisBlock) {
			return TES3_ui_createWidget(this, id, TES3_ui_factorySliderVert, bReplaceThisBlock);
		}

		Block* Block::createTextInput(UI_ID id, Boolean bReplaceThisBlock) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryTextInput, bReplaceThisBlock);
		}

		Block* Block::createTextSelect(UI_ID id, Boolean bReplaceThisBlock) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryTextSelect, bReplaceThisBlock);
		}

		Block* Block::createVerticalScrollPane(UI_ID id, Boolean bReplaceThisBlock) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryVertScrollPane, bReplaceThisBlock);
		}

		void Block::destroy() {
			TES3_deleting_dtor_UIBlock(this, 1);
		}

		//
		// Layout methods
		//

		Block* Block::findChild(UI_ID id) {
			return TES3_ui_findChildBlock(this, id);
		}

		Block* Block::performLayout(Boolean bUpdateTimestamp) {
			return TES3_ui_performLayout(this, bUpdateTimestamp);
		}

		void Block::setAutoHeight(Boolean bAuto) {
			return TES3_ui_setAutoHeight(this, bAuto);
		}

		void Block::setAutoWidth(Boolean bAuto) {
			return TES3_ui_setAutoWidth(this, bAuto);
		}

		void Block::setVisible(Boolean bVisible) {
			return TES3_ui_setVisible(this, bVisible);
		}

		long Block::timingUpdate() {
			return TES3_ui_timingUpdate(this);
		}

		//
		// Property methods
		//

		PropertyValue Block::getProperty(PropertyType propType, Property prop) const {
			PropertyValue v;
			TES3_ui_getProperty(this, &v, prop, propType, nullptr, 0);
			return v;
		}

		void Block::setProperty(Property prop, int value) {
			PropertyValue v;
			v.integerValue = value;
			TES3_ui_setProperty(this, prop, v, PropertyType::Integer);
		}

		void Block::setProperty(Property prop, float value) {
			PropertyValue v;
			v.floatValue = value;
			TES3_ui_setProperty(this, prop, v, PropertyType::Float);
		}

		void Block::setProperty(Property prop, void* value) {
			PropertyValue v;
			v.ptrValue = value;
			TES3_ui_setProperty(this, prop, v, PropertyType::Pointer);
		}

		void Block::setProperty(Property prop, Property value) {
			PropertyValue v;
			v.propertyValue = value;
			TES3_ui_setProperty(this, prop, v, PropertyType::Property);
		}

		void Block::setProperty(Property prop, EventCallback value) {
			PropertyValue v;
			v.eventCallback = value;
			TES3_ui_setProperty(this, prop, v, PropertyType::EventCallback);
		}

		void Block::setProperty(Property prop, PropertyAccessCallback value) {
			PropertyValue v;
			v.propertyCallback = value;
			TES3_ui_setProperty(this, prop, v, PropertyType::PropertyAccessCallback);
		}

		const char* Block::getText() const {
			return TES3_ui_getText(this);
		}

		void Block::setText(const char* text) {
			TES3_ui_setText(this, text);
		}

	}
}

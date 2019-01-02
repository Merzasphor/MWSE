#include "string.h"
#include <vector>

#include "TES3UIManager.h"
#include "TES3UIElement.h"

namespace TES3 {
	namespace UI {
		typedef Element* (__cdecl *TES3_UI_WidgetFactoryMethod_t)(Element*);

		const auto TES3_ui_createBlock = reinterpret_cast<Element* (__thiscall *)(Element*, UI_ID, Boolean)>(0x588980);
		const auto TES3_ui_createImage = reinterpret_cast<Element* (__thiscall *)(Element*, UI_ID, const char*, Boolean)>(0x588630);
		const auto TES3_ui_createLabel = reinterpret_cast<Element* (__thiscall *)(Element*, UI_ID, const char*, Boolean, Boolean)>(0x588BE0);
		const auto TES3_ui_createNif = reinterpret_cast<Element* (__thiscall *)(Element*, UI_ID, const char*, Boolean)>(0x588830);
		const auto TES3_ui_createRect = reinterpret_cast<Element* (__thiscall *)(Element*, UI_ID, Boolean, Boolean)>(0x588340);
		const auto TES3_ui_createWidget = reinterpret_cast<Element* (__thiscall *)(Element*, UI_ID, TES3_UI_WidgetFactoryMethod_t, Boolean)>(0x588140);
		const auto TES3_deleting_dtor_UIElement = reinterpret_cast<void (__thiscall *)(Element*, char)>(0x578880);
		const auto TES3_ui_destroyChildren = reinterpret_cast<void (__thiscall *)(Element*)>(0x578820);

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

		const auto TES3_ui_findChildElement = reinterpret_cast<Element* (__thiscall *)(const Element*, UI_ID)>(0x582DE0);
		const auto TES3_ui_getTopLevelParent = reinterpret_cast<Element* (__thiscall *)(const Element*)>(0x582EF0);
		const auto TES3_ui_performLayout = reinterpret_cast<Element* (__thiscall *)(Element*, Boolean)>(0x583B70);
		const auto TES3_ui_setAutoHeight = reinterpret_cast<void (__thiscall *)(Element*, Boolean)>(0x581400);
		const auto TES3_ui_setAutoWidth = reinterpret_cast<void (__thiscall *)(Element*, Boolean)>(0x5813C0);
		const auto TES3_ui_setVisible = reinterpret_cast<void (__thiscall *)(Element*, Boolean)>(0x57F2A0);
		const auto TES3_ui_timingUpdate = reinterpret_cast<long (__thiscall *)(Element*)>(0x583B60);
		const auto TES3_ui_updateLayout_propagateFlow = reinterpret_cast<void(__thiscall*)(Element*)>(0x584850);
		const auto TES3_ui_updateLayoutContent = reinterpret_cast<void(__thiscall*)(Element*)>(0x583760);

		const auto TES3_ui_getProperty = reinterpret_cast<PropertyValue* (__thiscall *)(const Element*, PropertyValue*, Property, PropertyType, const Element*, Boolean)>(0x581440);
		const auto TES3_ui_getText = reinterpret_cast<const char* (__thiscall *)(const Element*)>(0x580BB0);
		const auto TES3_ui_setProperty = reinterpret_cast<void (__thiscall *)(Element*, Property, PropertyValue, PropertyType)>(0x581F30);
		const auto TES3_ui_setText = reinterpret_cast<void(__thiscall *)(Element*, const char*)>(0x58AD30);
		const auto TES3_ui_setIcon = reinterpret_cast<void(__thiscall *)(Element*, const char*)>(0x58AE20);
		const auto TES3_ui_setIconString = reinterpret_cast<void(__thiscall *)(Element*, String)>(0x58AF10);

		const auto TES3_ui_updateSceneGraph = reinterpret_cast<void(__thiscall *)(Element*)>(0x587000);

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
			return TES3_ui_createNif(this, id, path, bReplaceThisElement);
		}

		Element* Element::createParagraphInput(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createWidget(this, id, TES3_ui_factoryParagraphInput, bReplaceThisElement);
		}

		Element* Element::createRect(UI_ID id, Boolean bReplaceThisElement, Boolean bRandomColour) {
			return TES3_ui_createRect(this, id, bReplaceThisElement, bRandomColour);
		}

		Element* Element::createSlider(UI_ID id, Boolean bReplaceThisElement) {
			return TES3_ui_createWidget(this, id, TES3_ui_factorySlider, bReplaceThisElement);
		}

		Element* Element::createSliderVertical(UI_ID id, Boolean bReplaceThisElement) {
			Element* slider = TES3_ui_createWidget(this, id, TES3_ui_factorySliderVert, bReplaceThisElement);
			// Set is_part prop to correct value for WidgetScrollBar
			static Property propPart = registerProperty("PartScrollBar");
			slider->setProperty(Property::is_part, propPart);
			return slider;
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

		void Element::destroyChildren() {
			TES3_ui_destroyChildren(this);
		}

		//
		// Layout methods
		//

		Element* Element::findChild(UI_ID id) const {
			return TES3_ui_findChildElement(this, id);
		}

		int Element::getIndexOfChild(const Element *child) const {
			Element** it = vectorChildren.begin;
			Element** end = vectorChildren.end;

			for (int i = 0; it != this->vectorChildren.end; ++i, ++it) {
				if (*it == child) {
					return i;
				}
			}
			return -1;
		}

		Element* Element::getContentElement() {
			Property shunt = getProperty(PropertyType::Property, Property::shunt_children).propertyValue;
			return int(shunt) ? findChild(static_cast<UI_ID>(shunt)) : this;
		}

		Element* Element::getTopLevelParent() {
			return TES3_ui_getTopLevelParent(this);
		}

		Element* Element::performLayout(Boolean bUpdateTimestamp) {
			return TES3_ui_performLayout(this, bUpdateTimestamp);
		}

		bool Element::reorderChildren(int insertBefore, int moveFrom, int count) {
			// Move <count> children from index <moveFrom> to index <insertBefore>
			// Negative positions indicate distance from end, negative count moves all children after moveFrom
			if (vectorChildren.begin == vectorChildren.end) {
				return false;
			}

			Element** begin = vectorChildren.begin;
			Element** end = vectorChildren.end;
			int childCount = int(end - begin);

			// Convert negative indices to distance from end, and negative count to move all items after moveFrom
			insertBefore = (insertBefore < 0) ? childCount + insertBefore : insertBefore;
			moveFrom = (moveFrom < 0) ? childCount + moveFrom : moveFrom;
			count = (count < 0) ? childCount - moveFrom : count;

			// Array bounds checks
			if (insertBefore < 0 || insertBefore > childCount || moveFrom < 0 || moveFrom >= childCount || count < 0 || count + moveFrom > childCount) {
				return false;
			}

			// Copy <count> elements into a temp buffer
			Element** from = begin + moveFrom, ** to = begin + insertBefore;
			std::vector<const Element*> temp(from, from + count);

			// Slide <shift> children in-place, then write buffer into correct location
			if (moveFrom < insertBefore) {
				int shift = insertBefore - moveFrom;
				memmove_s(from, sizeof(Element*) * shift, from + count, sizeof(Element*) * shift);
				memmove_s(to - count, sizeof(Element*) * count, &*temp.begin(), sizeof(Element*) * count);
			}
			else {
				int shift = moveFrom - insertBefore;
				memmove_s(to + count, sizeof(Element*) * shift, to, sizeof(Element*) * shift);
				memmove_s(to, sizeof(Element*) * count, &*temp.begin(), sizeof(Element*) * count);
			}

			return true;
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

		PropertyValue* Element::getProperty(PropertyValue* propValue, Property prop, PropertyType propType, const Element* element, bool checkInherited) const {
			return TES3_ui_getProperty(this, propValue, prop, propType, element, checkInherited);
		}

		PropertyValue Element::getProperty(PropertyType propType, Property prop) const {
			PropertyValue v;
			TES3_ui_getProperty(this, &v, prop, propType, nullptr, 0);
			return v;
		}

		void Element::setProperty(Property prop, PropertyValue value, PropertyType type) {
			TES3_ui_setProperty(this, prop, value, type);
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

		void Element::setIcon(const char* path) {
			TES3_ui_setIcon(this, path);
		}

		void Element::setIcon(String path) {
			TES3_ui_setIconString(this, path);
		}

		void Element::updateSceneGraph() {
			TES3_ui_updateSceneGraph(this);
		}

		//
		// Patch methods
		//
		void Element::patchUpdateLayout_propagateFlow() {
			// Call original function
			TES3_ui_updateLayout_propagateFlow(this);

			// On size change, reflow wrapped text
			if (flagSizeChanged && rawText.length) {
				auto wrapped = getProperty(PropertyType::Property, Property::wrap_text).propertyValue;
				if (wrapped == Property::boolean_true) {
					flagContentChanged = 1;
					TES3_ui_updateLayoutContent(this);
				}
			}
		}

	}
}

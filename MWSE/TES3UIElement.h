#pragma once

#include "TES3Defines.h"

#include "TES3UIString.h"
#include "TES3UITree.h"
#include "TES3UIVector.h"

namespace TES3 {
	namespace UI {
		struct Element {
			char tag;
			String name;
			short id;
			Vector vectorChildren;
			Element* parent;
			Tree properties;
			Element* uielement_3C;
			Vector vectorVerts_40;
			Vector vector_50;
			Vector vector_60;
			int updateReqTimestamp;
			Boolean flagExtendImageToBounds;
			Boolean visible;
			Boolean visibleAtLastUpdate;
			Boolean flagUsesRGBA;
			Boolean flagPosChanged;
			Boolean flagSizeChanged;
			Boolean flagVisibilityChanged;
			Boolean flagClippingChanged;
			Boolean flagContentChanged;
			char unknown_0x7D;
			char unknown_0x7E;
			Boolean flagConsumeMouseEvents;
			char unknown_0x80;
			char unknown_0x81;
			char unknown_0x82;
			char unknown_0x83;
			int unknown_0x84;
			void* node_88;
			void* extraData;
			void* node_90;
			int cached_offsetX, cached_offsetY;
			int nodeMinX, nodeMaxX;
			int nodeMinY, nodeMaxY;
			int cached_unknown_x, cached_unknown_y;
			int borderAllSides;
			int borderLeft, borderRight, borderBottom, borderTop;
			int paddingAllSides;
			int paddingLeft, paddingRight, paddingBottom, paddingTop;
			int positionX, positionY;
			int unknown_0xE4;
			int unknown_0xE8;
			int width, height;
			int childOffsetX, childOffsetY;
			int minWidth, minHeight;
			int maxWidth, maxHeight;
			int inheritedWidth, inheritedHeight;
			char flagAutoWidth, flagAutoHeight;
			float widthProportional, heightProportional;
			float absolutePosAlignX, absolutePosAlignY;
			int clipMinX, clipMaxX;
			int clipMinY, clipMaxY;
			Property scale_mode;
			int nodeOffsetX, nodeOffsetY;
			float imageScaleX, imageScaleY;
			float colourRed, colourGreen, colourBlue, colourAlpha;
			int font;
			Property contentType;
			String rawText;
			String contentPath;

			//
			// Widget creation/destruction methods
			//

			Element* createBlock(UI_ID id, Boolean bReplaceThisElement = 0);
			Element* createButton(UI_ID id, Boolean bReplaceThisElement = 0);
			Element* createDragFrame(UI_ID id, Boolean bReplaceThisElement = 0);
			Element* createFillBar(UI_ID id, Boolean bReplaceThisElement = 0);
			Element* createFixedFrame(UI_ID id, Boolean bReplaceThisElement = 0);
			Element* createHorizontalScrollPane(UI_ID id, Boolean bReplaceThisElement = 0);
			Element* createHypertext(UI_ID id, Boolean bReplaceThisElement = 0);
			Element* createImage(UI_ID id, const char* imagePath, Boolean bReplaceThisElement = 0);
			Element* createLabel(UI_ID id, const char* text, Boolean bBlackText = 0, Boolean bReplaceThisElement = 0);
			Element* createNif(UI_ID id, const char* path, Boolean bReplaceThisElement = 0);
			Element* createParagraphInput(UI_ID id, Boolean bReplaceThisElement = 0);
			Element* createRect(UI_ID id, Boolean bReplaceThisElement = 0, Boolean bRandomColour = 0);
			Element* createSlider(UI_ID id, Boolean bReplaceThisElement = 0);
			Element* createSliderVertical(UI_ID id, Boolean bReplaceThisElement = 0);
			Element* createTextInput(UI_ID id, Boolean bReplaceThisElement = 0);
			Element* createTextSelect(UI_ID id, Boolean bReplaceThisElement = 0);
			Element* createVerticalScrollPane(UI_ID id, Boolean bReplaceThisElement = 0);
			void destroy();
			void destroyChildren();

			//
			// Layout methods
			//

			Element* findChild(UI_ID id) const;
			int getIndexOfChild(const Element *child) const;
			Element* getContentElement();
			Element* getTopLevelParent();
			Element* performLayout(Boolean bUpdateTimestamp = 1);
			bool reorderChildren(int insertBefore, int moveFrom, int count);
			void setAutoHeight(Boolean bAuto);
			void setAutoWidth(Boolean bAuto);
			void setVisible(Boolean bVisible);
			long timingUpdate();

			//
			// Property methods
			//

			PropertyValue* getProperty(PropertyValue* propValue, Property prop, PropertyType propType, const Element* element = nullptr, bool checkInherited = false) const;
			PropertyValue getProperty(PropertyType propType, Property prop) const;
			const char* getText() const;

			void setProperty(Property prop, PropertyValue value, PropertyType type);
			void setProperty(Property prop, int value);
			void setProperty(Property prop, float value);
			void setProperty(Property prop, void* value);
			void setProperty(Property prop, Property value);
			void setProperty(Property prop, EventCallback value);
			void setProperty(Property prop, PropertyAccessCallback value);
			void setText(const char *);

			//
			// Patch methods
			//
			void patchUpdateLayout_propagateFlow();

		};
		static_assert(sizeof(Element) == 0x184, "TES3::UI::Element failed size validation");
	}
}

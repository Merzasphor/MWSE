#pragma once

#include "TES3Defines.h"

#include "TES3UIString.h"
#include "TES3UITree.h"
#include "TES3UIVector.h"

#include "NIPointer.h"
#include "NINode.h"
#include "NISourceTexture.h"

namespace TES3 {
	namespace UI {
		struct Element {
			char tag;
			String name;
			short id;
			Vector<Element*> vectorChildren;
			Element* parent;
			Tree properties;
			Element* uielement_3C;
			Vector<void> vectorVerts_40;
			Vector<void> vector_50;
			Vector<void> vector_60;
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
			NI::Pointer<NI::Node> node_88;
			void* extraData;
			NI::Pointer<NI::SourceTexture> texture; // 0x90
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

			__declspec(dllexport) Element* createBlock(UI_ID id, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createButton(UI_ID id, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createDragFrame(UI_ID id, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createFillBar(UI_ID id, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createFixedFrame(UI_ID id, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createHorizontalScrollPane(UI_ID id, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createHypertext(UI_ID id, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createImage(UI_ID id, const char* imagePath, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createLabel(UI_ID id, const char* text, Boolean bBlackText = 0, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createNif(UI_ID id, const char* path, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createParagraphInput(UI_ID id, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createRect(UI_ID id, Boolean bReplaceThisElement = 0, Boolean bRandomColour = 0);
			__declspec(dllexport) Element* createSlider(UI_ID id, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createSliderVertical(UI_ID id, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createTextInput(UI_ID id, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createTextSelect(UI_ID id, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) Element* createVerticalScrollPane(UI_ID id, Boolean bReplaceThisElement = 0);
			__declspec(dllexport) void destroy();
			__declspec(dllexport) void destroyChildren();

			//
			// Layout methods
			//

			__declspec(dllexport) Element* findChild(UI_ID id) const;
			__declspec(dllexport) int getIndexOfChild(const Element *child) const;
			__declspec(dllexport) Element* getContentElement();
			__declspec(dllexport) Element* getTopLevelParent();
			__declspec(dllexport) Element* performLayout(Boolean bUpdateTimestamp = 1);
			__declspec(dllexport) bool reorderChildren(int insertBefore, int moveFrom, int count);
			__declspec(dllexport) void setAutoHeight(Boolean bAuto);
			__declspec(dllexport) void setAutoWidth(Boolean bAuto);
			__declspec(dllexport) void setVisible(Boolean bVisible);
			__declspec(dllexport) long timingUpdate();

			//
			// Property methods
			//

			__declspec(dllexport) PropertyValue* getProperty(PropertyValue* propValue, Property prop, PropertyType propType, const Element* element = nullptr, bool checkInherited = false) const;
			__declspec(dllexport) PropertyValue getProperty(PropertyType propType, Property prop) const;
			__declspec(dllexport) const char* getText() const;

			__declspec(dllexport) void setProperty(Property prop, PropertyValue value, PropertyType type);
			__declspec(dllexport) void setProperty(Property prop, int value);
			__declspec(dllexport) void setProperty(Property prop, float value);
			__declspec(dllexport) void setProperty(Property prop, void* value);
			__declspec(dllexport) void setProperty(Property prop, Property value);
			__declspec(dllexport) void setProperty(Property prop, EventCallback value);
			__declspec(dllexport) void setProperty(Property prop, PropertyAccessCallback value);
			__declspec(dllexport) void setText(const char *);
			__declspec(dllexport) void setIcon(const char *);
			__declspec(dllexport) void setIcon(String);

			//
			// Other related this-call functions.
			//

			__declspec(dllexport) void updateSceneGraph();

			//
			// Patch methods
			//

			void patchUpdateLayout_propagateFlow();

		};
		static_assert(sizeof(Element) == 0x184, "TES3::UI::Element failed size validation");
	}
}

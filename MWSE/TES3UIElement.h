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
			bool flagExtendImageToBounds;
			bool visible;
			bool visibleAtLastUpdate;
			bool flagUsesRGBA;
			bool flagPosChanged;
			bool flagSizeChanged;
			bool flagVisibilityChanged;
			bool flagClippingChanged;
			bool flagContentChanged;
			char unknown_0x7D;
			char unknown_0x7E;
			bool flagConsumeMouseEvents;
			char unknown_0x80;
			char unknown_0x81;
			char unknown_0x82;
			char unknown_0x83;
			int unknown_0x84;
			NI::Pointer<NI::Node> sceneNode;
			void* extraData;
			NI::Pointer<NI::SourceTexture> texture;
			int cached_offsetX, cached_offsetY;
			int nodeMinX, nodeMaxX;
			int nodeMinY, nodeMaxY;
			int cached_unknown_x, cached_unknown_y;
			int borderAllSides;
			int borderLeft, borderRight, borderBottom, borderTop;
			int paddingAllSides;
			int paddingLeft, paddingRight, paddingBottom, paddingTop;
			int positionX, positionY;
			int cached_screenX, cached_screenY;
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

			Element* createBlock(UI_ID id, bool bReplaceThisElement = false);
			Element* createButton(UI_ID id, bool bReplaceThisElement = false);
			Element* createDragFrame(UI_ID id, bool bReplaceThisElement = false);
			Element* createFillBar(UI_ID id, bool bReplaceThisElement = false);
			Element* createFixedFrame(UI_ID id, bool bReplaceThisElement = false);
			Element* createHorizontalScrollPane(UI_ID id, bool bReplaceThisElement = false);
			Element* createHypertext(UI_ID id, bool bReplaceThisElement = false);
			Element* createImage(UI_ID id, const char* imagePath, bool bReplaceThisElement = false);
			Element* createLabel(UI_ID id, const char* text, bool bBlackText = 0, bool bReplaceThisElement = false);
			Element* createNif(UI_ID id, const char* path, bool bReplaceThisElement = false);
			Element* createParagraphInput(UI_ID id, bool bReplaceThisElement = false);
			Element* createRect(UI_ID id, bool bReplaceThisElement = 0, bool bRandomColour = false);
			Element* createSlider(UI_ID id, bool bReplaceThisElement = false);
			Element* createSliderVertical(UI_ID id, bool bReplaceThisElement = false);
			Element* createTextInput(UI_ID id, bool bReplaceThisElement = false);
			Element* createTextSelect(UI_ID id, bool bReplaceThisElement = false);
			Element* createVerticalScrollPane(UI_ID id, bool bReplaceThisElement = false);
			void destroy();
			void destroyChildren();

			//
			// Layout methods
			//

			Element* findChild(UI_ID id) const;
			int getIndexOfChild(const Element *child) const;
			Element* getContentElement();
			Element* getTopLevelParent();
			Element* performLayout(bool bUpdateTimestamp = true);
			bool reorderChildren(int insertBefore, int moveFrom, int count);
			void setAutoHeight(bool bAuto);
			void setAutoWidth(bool bAuto);
			void setVisible(bool bVisible);
			long timingUpdate();

			//
			// Property methods
			//

			PropertyValue* getProperty(PropertyValue* propValue, Property prop, PropertyType propType, const Element* element = nullptr, bool checkInherited = false) const;
			PropertyValue getProperty(PropertyType propType, Property prop) const;
			PropertyType getPropertyType(Property prop) const;
			bool hasProperty(Property prop) const;
			const char* getText() const;

			void setProperty(Property prop, PropertyValue value, PropertyType type);
			void setProperty(Property prop, int value);
			void setProperty(Property prop, float value);
			void setProperty(Property prop, void* value);
			void setProperty(Property prop, Property value);
			void setProperty(Property prop, EventCallback value);
			void setProperty(Property prop, PropertyAccessCallback value);
			void setText(const char *);
			void setIcon(const char *);
			void setIcon(String);

			//
			// Other related this-call functions.
			//

			void updateSceneGraph();

			//
			// Patch methods
			//

			void patchUpdateLayout_propagateFlow();

		};
		static_assert(sizeof(Element) == 0x184, "TES3::UI::Element failed size validation");
	}
}

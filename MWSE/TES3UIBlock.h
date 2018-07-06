#pragma once

#include "TES3Defines.h"

#include "TES3UIString.h"
#include "TES3UITree.h"
#include "TES3UIVector.h"

namespace TES3 {
	namespace UI {
		struct Block {
			char tag;
			String name;
			short id;
			Vector vectorChildren;
			Block* parent;
			Tree properties;
			Block* uiblock_3C;
			Vector vectorVerts_40;
			Vector vector_50;
			Vector vector_60;
			int updateReqTimestamp;
			char unknown_0x74;
			Boolean visible;
			Boolean flagUpdateWhenHidden_maybe;
			Boolean flagUsesRGBA;
			Boolean flagPosChanged;
			Boolean flagSizeChanged;
			Boolean flagVisibilityChanged;
			char flagClippingChanged;
			Boolean flagContentTypeChanged;
			char unknown_0x7D;
			char unknown_0x7E;
			char unknown_0x7F;
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
			float layoutWidthFraction, layoutHeightFraction;
			float layoutOriginFractionX, layoutOriginFractionY;
			int clipMinX, clipMaxX;
			int clipMinY, clipMaxY;
			Property scale_mode;
			int nodeOffsetX, nodeOffsetY;
			int scaleX, scaleY;
			float colourRed, colourGreen, colourBlue, colourAlpha;
			int font;
			Property contentType;
			String rawText;
			String imagePath;

			//
			// Widget creation/destruction methods
			//

			Block* createBlock(UI_ID id, Boolean bReplaceThisBlock = 0);
			Block* createButton(UI_ID id, Boolean bReplaceThisBlock = 0);
			Block* createDragFrame(UI_ID id, Boolean bReplaceThisBlock = 0);
			Block* createFillBar(UI_ID id, Boolean bReplaceThisBlock = 0);
			Block* createFixedFrame(UI_ID id, Boolean bReplaceThisBlock = 0);
			Block* createHorizontalScrollPane(UI_ID id, Boolean bReplaceThisBlock = 0);
			Block* createHypertext(UI_ID id, Boolean bReplaceThisBlock = 0);
			Block* createImage(UI_ID id, const char* imagePath, Boolean bReplaceThisBlock = 0);
			Block* createLabel(UI_ID id, const char* text, Boolean bBlackText = 0, Boolean bReplaceThisBlock = 0);
			Block* createNif(UI_ID id, const char* path, Boolean bReplaceThisBlock = 0);
			Block* createParagraphInput(UI_ID id, Boolean bReplaceThisBlock = 0);
			Block* createSlider(UI_ID id, Boolean bReplaceThisBlock = 0);
			Block* createSliderVertical(UI_ID id, Boolean bReplaceThisBlock = 0);
			Block* createTextInput(UI_ID id, Boolean bReplaceThisBlock = 0);
			Block* createTextSelect(UI_ID id, Boolean bReplaceThisBlock = 0);
			Block* createVerticalScrollPane(UI_ID id, Boolean bReplaceThisBlock = 0);
			void destroy();

			//
			// Layout methods
			//

			Block* findChild(UI_ID id);
			Block* performLayout(Boolean bUpdateTimestamp = 1);
			void setAutoHeight(Boolean bAuto);
			void setAutoWidth(Boolean bAuto);
			void setVisible(Boolean bVisible);
			long timingUpdate();

			//
			// Property methods
			//

			PropertyValue getProperty(PropertyType propType, Property prop) const;
			const char* getText() const;

			void setProperty(Property prop, int value);
			void setProperty(Property prop, float value);
			void setProperty(Property prop, void* value);
			void setProperty(Property prop, Property value);
			void setProperty(Property prop, EventCallback value);
			void setProperty(Property prop, PropertyAccessCallback value);
			void setText(const char *);

		};
		static_assert(sizeof(Block) == 0x184, "TES3::UI::Block failed size validation");
	}
}

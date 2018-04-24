#pragma once

#include "TES3Object.h"

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
			Block *parent;
			Tree properties;
			int unknown_0x34;
			int unknown_0x38;
			Block * uiblock_3C;
			Vector vectorVerts_40;
			Vector vector_50;
			Vector vector_60;
			int updateReqTimestamp;
			char unknown_0x74;
			unsigned char visible;
			unsigned char alwaysUpdate_maybe;
			unsigned char flagUsesRGBA;
			unsigned char flagPosChanged;
			unsigned char flagSizeChanged;
			char flagUnknownChanged_7A;
			char unknown_0x7B;
			unsigned char flagUsesBlending;
			char unknown_0x7D;
			char unknown_0x7E;
			char unknown_0x7F;
			char unknown_0x80;
			char unknown_0x81;
			char unknown_0x82;
			char unknown_0x83;
			int unknown_0x84;
			void *node_88;
			void *extraData;
			void *node_90;
			int cached_offsetX;
			int cached_offsetY;
			int nodeMinX;
			int nodeMaxX;
			int nodeMinY;
			int nodeMaxY;
			int cached_unknown_x;
			int cached_unknown_y;
			int borderAllSides;
			int borderLeft;
			int borderRight;
			int borderBottom;
			int borderTop;
			int paddingAllSides;
			int paddingLeft;
			int paddingRight;
			int paddingBottom;
			int paddingTop;
			int positionX;
			int positionY;
			int unknown_0xE4;
			int unknown_0xE8;
			int width;
			int height;
			int childOffsetX;
			int childOffsetY;
			int minWidth;
			int minHeight;
			int maxWidth;
			int maxHeight;
			int unknown_0x10C;
			int unknown_0x110;
			char unknown_0x114;
			char unknown_0x115;
			float layoutWidthFraction;
			float layoutHeightFraction;
			float layoutOriginFractionX;
			float layoutOriginFractionY;
			int clipMinX;
			int clipMaxX;
			int clipMinY;
			int clipMaxY;
			short scale;
			int nodeOffsetX;
			int nodeOffsetY;
			int scaleX;
			int scaleY;
			float colourRed;
			float colourGreen;
			float colourBlue;
			float colourAlpha;
			int font;
			int type;
			String bodyText;
			String iconPath;

			//
			// Other related this-call functions.
			//

			Block* performLayout(signed char);
			long timingUpdate();

		};
		static_assert(sizeof(Block) == 0x184, "TES3::UI::Block failed size validation");
	}
}

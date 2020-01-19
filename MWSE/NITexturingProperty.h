#pragma once

#include "NIDefines.h"

#include "NIPointer.h"
#include "NIProperty.h"
#include "NISourceTexture.h"

#include "TES3Collections.h"

namespace NI {
	struct TexturingProperty : Property {
		struct Map {
			void* vTable; // 0x0
			Pointer<SourceTexture> texture; // 0x4
			int clampingMode; // 0x8
			int filterMode; // 0xC
			int textureCoordinateIndex; // 0x10
		};

		int unknown_0x18;
		TES3::TArray<Map> maps; // 0x1C
		int unknown_0x34;
	};
	static_assert(sizeof(TexturingProperty) == 0x38, "NI::TexturingProperty failed size validation");
	static_assert(sizeof(TexturingProperty::Map) == 0x14, "NI::TexturingProperty::Map failed size validation");
}

#pragma once

#include "NIDefines.h"

#include "NIObject.h"
#include "NIPixelFormat.h"

namespace NI {
	struct PixelData : Object {
		int pixelFormatFormat; // 0x8
		int pixelFormat_unknown_0x4; // 0xC
		int pixelFormat_unknown_0x8; // 0x10
		int pixelFormat_unknown_0xC; // 0x14
		int pixelFormat_unknown_0x10; // 0x18
		int pixelFormat_unknown_0x14; // 0x1C
		int pixelFormat_unknown_0x18; // 0x20
		int pixelFormat_unknown_0x1C; // 0x24
		int unknown_0x28;
		unsigned char * pixels; // 0x2C // The raw pixel data, in the given format. Hardcoded to RGB for now.
		unsigned int * widths; // 0x30 // An array of widths by mip map level.
		unsigned int * heights; // 0x34 // An array of heights by mip map level.
		unsigned int * offsets; // 0x38 // Offsets into 'pixels' for each mip map level, including 0 (length = mipMapLevels + 1).
		unsigned int mipMapLevels; // 0x3C // The number of mip map levels.
		unsigned int bytesPerPixel; // 0x40 // Determined by format data.
		int unknown_0x44;
	};
	static_assert(sizeof(PixelData) == 0x48, "NI::PixelData failed size validation");
}

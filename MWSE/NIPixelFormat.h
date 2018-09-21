#pragma once

#include "NIDefines.h"

namespace NI {
	struct PixelFormat {
		int format; // 0x0
		int unknown_0x4;
		int unknown_0x8;
		int unknown_0xC;
		int unknown_0x10;
		unsigned char bitsPerPixel; // 0x14
		int unknown_0x18;
		int unknown_0x1C;
		int unknown_0x20;
		int unknown_0x24; // Maybe bits per pixel?
	};
	static_assert(sizeof(PixelFormat) == 0x28, "NI::PixelFormat failed size validation");

	struct PixelRGB {
		unsigned char r;
		unsigned char g;
		unsigned char b;
	};
	static_assert(sizeof(PixelRGB) == 0x3, "NI::PixelRGB failed size validation");
}

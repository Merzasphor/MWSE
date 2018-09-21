#pragma once

#include "NIObjectNET.h"
#include "NIPixelFormat.h"
#include "NIPixelData.h"

namespace NI {
	struct SourceTexture : ObjectNET {
		struct FormatPrefs {
			int unknown_0x0;
			int unknown_0x4;
			int unknown_0x8;
		};
		FormatPrefs formatPrefs; // 0x14;
		int unknown_0x20;
		int unknown_0x24;
		int unknown_0x28;
		int unknown_0x2C;
		int unknown_0x30;
		Pointer<PixelData> pixelData; // 0x34
		int unknown_0x38;
	};
	static_assert(sizeof(SourceTexture) == 0x3C, "NI::SourceTexture failed size validation");
}

#pragma once

#include "NIDefines.h"

#include "NIDynamicEffect.h"
#include "NISourceTexture.h"
#include "TES3Vectors.h"

namespace NI {
	struct TextureEffect : DynamicEffect {
		TextureEffect();
		~TextureEffect();

		TES3::Matrix33 unknown_0xA8;
		TES3::Vector3 unknnown_0xCC;
		TES3::Matrix33 unknown_0xD8;
		TES3::Vector3 unknnown_0xFC;
		Pointer<SourceTexture> sourceTexture; // 0x108
		int unknown_0x10C;
		int unknown_0x110;
		int unknown_0x114;
		int unknown_0x118;
		int unknown_0x11C;
		int unknown_0x120;
		int unknown_0x124;
		int unknown_0x128;
		int unknown_0x12C;
		int unknown_0x130;
		int unknown_0x134;
		int unknown_0x138;
		int unknown_0x13C;
		int unknown_0x140;
		int unknown_0x144;
	};
	static_assert(sizeof(TextureEffect) == 0x148, "NI::TextureEffect failed size validation");
}

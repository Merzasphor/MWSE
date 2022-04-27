#pragma once

#include "NIColor.h"
#include "NIKeyframeController.h"

namespace NI {
	struct ColorKey : public AnimationKey {
		PackedColor color; // 0x4
	};
	static_assert(sizeof(ColorKey) == 0x8, "TES3::ColorKey failed size validation");
}

#pragma once

#include "NIObject.h"
#include "NIColorKey.h"

namespace NI {
	struct ColorData : public Object {
		unsigned int keyCount; // 0x8
		ColorKey** keys; // 0xC
		AnimationKeyType keyType; // 0x10

		nonstd::span<ColorKey*> getKeys() const;
	};
	static_assert(sizeof(ColorData) == 0x14, "NI::ColorData failed size validation");
}

MWSE_SOL_CUSTOMIZED_PUSHER_DECLARE_NI(NI::ColorData)

#pragma once

#include "NIObject.h"
#include "NIKeyframeController.h"

namespace NI {
	struct PosData : Object {
		unsigned int keyCount; // 0x8
		AmbiguousPosKeyPtr keys; // 0xC
		AnimationKey::Type keyType; // 0x10

		unsigned int getKeyDataSize() const;
	};
	static_assert(sizeof(PosData) == 0x14, "NI::PosData failed size validation");
}

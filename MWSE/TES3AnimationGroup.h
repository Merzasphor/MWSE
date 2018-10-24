#pragma once

#include "TES3Object.h"

namespace TES3 {
	struct AnimationGroup : BaseObject {
		unsigned char groupId; // 0x10
		int maxFrame; // 0x14
		int frameCount; // 0x18
		int unknown_0x1C;
		int unknown_0x20;
		int unknown_0x24;
		int unknown_0x28;
	};
	static_assert(sizeof(AnimationGroup) == 0x2C, "TES3::AnimationAttachment failed size validation");
}
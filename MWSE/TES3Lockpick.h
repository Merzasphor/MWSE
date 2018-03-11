#pragma once

#include "TES3Item.h"

namespace TES3 {
	struct Lockpick : ItemContained {
		float weight; // 0xA8
		long value; // 0xAC
		float quality; // 0xB0
		short maxCondition; // 0xB4
		short unknown_0xB6;
	};
	static_assert(sizeof(Lockpick) == 0xB8, "TES3::Lockpick failed size validation");
}

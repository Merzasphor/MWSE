#pragma once

#include "TES3Item.h"

namespace TES3 {
	struct Misc : Item {
		float weight; // 0x54
		long value; // 0x58
		int unknown_0x5C;
	};
	static_assert(sizeof(Misc) == 0x60, "TES3::Misc failed size validation");
}

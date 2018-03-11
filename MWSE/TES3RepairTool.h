#pragma once

#include "TES3Item.h"

namespace TES3 {
	struct RepairTool : ItemContained {
		float weight; // 0xA8
		long value; // 0xAC
		short maxCondition; // 0xB0
		short unknown_0xB2;
		float quality; // 0xB4
	};
	static_assert(sizeof(RepairTool) == 0xB8, "TES3::RepairTool failed size validation");
}

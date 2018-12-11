#pragma once

#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3Item.h"

namespace TES3 {
	struct RepairTool : Item {
		Iterator<TES3::BaseObject> stolenList; // 0x30
		char name[32]; // 0x44
		Script * script; // 0x64
		char modal[32]; // 0x68
		char icon[32]; // 0x88
		float weight; // 0xA8
		long value; // 0xAC
		short maxCondition; // 0xB0
		short unknown_0xB2;
		float quality; // 0xB4
	};
	static_assert(sizeof(RepairTool) == 0xB8, "TES3::RepairTool failed size validation");
}

#pragma once

#include "CSPhysicalObject.h"

namespace se::cs {
	struct RepairTool : PhysicalObject {
		char name[32]; // 0x48
		Script* script; // 0x68
		char model[32]; // 0x6C
		char icon[32]; // 0x8C
		float weight; // 0xAC
		int value; // 0xB0
		int uses; // 0xB4
		float quality; // 0xB8
	};
	static_assert(sizeof(RepairTool) == 0xBC, "RepairTool failed size validation");
}

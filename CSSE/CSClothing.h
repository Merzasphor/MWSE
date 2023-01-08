#pragma once

#include "CSPhysicalObject.h"
#include "CSWearablePart.h"

namespace se::cs {
	struct Clothing : PhysicalObject {
		char* name; // 0x48
		Script* script; // 0x4C
		char* model; // 0x50
		char* icon; // 0x54
		WearablePart parts[7]; // 0x58
		byte type; // 0xAC
		float weight; // 0xB0
		short value; // 0xB4
		short enchantPoints; // 0xB6
		Enchantment* enchantment; // 0xB8
	};
	static_assert(sizeof(Clothing) == 0xBC, "Clothing failed size validation");
}

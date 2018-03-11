#pragma once

#include "TES3Object.h"
#include "TES3MagicEffect.h"

namespace TES3 {
	struct Enchantment : Object {
		char * objectID; // 0x28
		short castType; // 0x2C
		short chargeCost; // 0x2E
		short maxCharge; // 0x30
		short magickaCost; // 0x32
		Effect effects[8]; // 0x34
		unsigned long flags; // 0xF4
	};
	static_assert(sizeof(Enchantment) == 0xF8, "TES3::Enchantment failed size validation");
}

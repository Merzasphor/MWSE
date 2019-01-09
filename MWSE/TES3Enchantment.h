#pragma once

#include "TES3Defines.h"

#include "TES3MagicEffect.h"
#include "TES3Object.h"

namespace TES3 {
	enum class EnchantmentCastType : unsigned short {
		Once,
		OnStrike,
		OnUse,
		Constant
	};

	namespace EnchantmentFlags {
		typedef unsigned int value_type;

		enum Flag : value_type {
		};
	}

	struct Enchantment : Object {
		char * objectID; // 0x28
		EnchantmentCastType castType; // 0x2C
		short chargeCost; // 0x2E
		short maxCharge; // 0x30
		short magickaCost; // 0x32
		Effect effects[8]; // 0x34
		EnchantmentFlags::value_type flags; // 0xF4

		//
		// Custom functions.
		//

		size_t getActiveEffectCount();

	};
	static_assert(sizeof(Enchantment) == 0xF8, "TES3::Enchantment failed size validation");
}

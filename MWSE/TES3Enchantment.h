#pragma once

#include "ObjectTypes.h"

#include "TES3Effect.h"

namespace TES3 {
	enum EnchantmentType {
		CastEnchantmentOnce,
		CastEnchantmentOnStrike,
		CastEnchantmentOnUse,
		ConstantEnchantment
	};

	struct Enchantment_vTable {

	};

	// TODO: Find autocalc flag.
	struct Enchantment {
		Enchantment_vTable * vTable;
		ObjectType::ObjectType objectType;
		int baseFlags; // 0x08
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		BaseObject * previousRecord; // 0x1C
		BaseObject * nextObject; // 0x20
		int unknown_0x24;
		mwString objectID; // 0x28
		short type;	// 0x2C // EnchantmentType
		short cost; // 0x2E
		long charge; // 0x30
		Effect effects[8]; // 0x34
		long autocalc; // 0xF4
	};
	static_assert(sizeof(Enchantment) == 0xF8, "TES3::Enchantment failed size validation");
}

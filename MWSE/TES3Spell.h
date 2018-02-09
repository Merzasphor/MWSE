#pragma once

#include "ObjectTypes.h"

#include "TES3Effect.h"

namespace TES3 {
	struct Spell_vTable {

	};

	struct Spell {
		Spell_vTable * vTable;
		ObjectType::ObjectType objectType;
		int baseFlags; // 0x08
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		BaseObject * previousRecord; // 0x1C
		BaseObject * nextRecord; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		mwString objectID; // 0x2C
		short type; // 0x30 // 0=SPELL, 1=ABILITY, 2=BLIGHT, 3=DISEASE, 4=CURSE, 5=POWER
		short cost; // 0x32
		Effect effects[8]; // 0x34
		long flags;	// 0xF4 // 1=AUTOCALC, 2=PCSTART, 4=ALWAYSSUCCEEDS
	};
	static_assert(sizeof(Spell) == 0xF8, "TES3::Spell failed size validation");
}

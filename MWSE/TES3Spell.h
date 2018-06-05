#pragma once

#include "TES3Defines.h"
#include "TES3MagicEffect.h"

namespace TES3 {
	namespace SpellCastType {
		enum SpellCastType {
			Spell = 0,
			Ability = 1,
			Blight = 2,
			Disease = 3,
			Curse = 4,
			Power = 5,

			FirstCastType = Spell,
			LastCastType = Power
		};
	}

	namespace SpellFlag {
		enum SpellFlag {
			AutoCalc = 0x1,
			PCStartSpell = 0x2,
			AlwaysSucceeds = 0x4,

			AllSpellFlags = (AutoCalc | PCStartSpell | AlwaysSucceeds),
			NoSpellFlags = 0
		};

		enum SpellFlagBit {
			AutoCalcBit = 0,
			PCStartSpellBit = 1,
			AlwaysSucceedsBit = 2
		};
	}

	namespace SpellOrigin {
		enum SpellOrigin {
			Module = 1,
			Spellmaker,
			FirstSpellOrigin = Module,
			LastSpellOrigin = Spellmaker
		};
	}

	struct Spell : Object {
		char * objectID; // 0x28
		char * name; // 0x2C
		signed char castType; // 0x30
		char unknown_0x31; // Undefined.
		short magickaCost; // 0x32
		Effect effects[8]; // 0x34
		int spellFlags; //  0xF4

		//
		// Other related this-call functions.
		//

		float calculateCastChance(Reference* caster, bool checkMagicka = true, int* weakestSchoolId = 0);
		float calculateCastChance(MobileActor* caster, bool checkMagicka = true, int* weakestSchoolId = 0);

	};
	static_assert(sizeof(Spell) == 0xF8, "TES3::Spell failed size validation");
}

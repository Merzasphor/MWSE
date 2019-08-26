#pragma once

#include "TES3Defines.h"
#include "TES3MagicEffect.h"

namespace TES3 {
	namespace SpellCastType {
		typedef unsigned char value_type;

		enum SpellCastType : value_type {
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
		typedef unsigned int value_type;

		enum Flag : value_type {
			AutoCalc = 0x1,
			PCStartSpell = 0x2,
			AlwaysSucceeds = 0x4,

			AllSpellFlags = (AutoCalc | PCStartSpell | AlwaysSucceeds),
			NoSpellFlags = 0
		};

		enum FlagBit {
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
		SpellCastType::value_type castType; // 0x30
		char unknown_0x31; // Undefined.
		unsigned short magickaCost; // 0x32
		Effect effects[8]; // 0x34
		mwse::bitset32 spellFlags; //  0xF4

		//
		// Other related this-call functions.
		//

		float calculateCastChance(Reference* caster, bool checkMagicka = true, int* weakestSchoolId = 0);
		float calculateCastChance(MobileActor* caster, bool checkMagicka = true, int* weakestSchoolId = 0);
		float castChanceOnCast(MobileActor* caster, bool checkMagicka, int* weakestSchoolId);

		//
		// Custom functions.
		//

		size_t getActiveEffectCount();
		int getFirstIndexOfEffect(int effectId);

	};
	static_assert(sizeof(Spell) == 0xF8, "TES3::Spell failed size validation");
}

#pragma once

#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3Object.h"

namespace TES3 {
	enum class SpellEffectState {
		PreCast = 0,
		Cast = 1,
		Beginning = 4,
		Working = 5,
		Ending = 6,
		Retired = 7,
		WorkingFortify = 8,
		EndingFortify = 9
	};

	enum class MagicSourceType : unsigned char {
		Spell = 1,
		Enchantment = 2,
		Alchemy = 3
	};

	struct MagicSourceCombo {
		union {
			Object * asGeneric;
			Alchemy * asAlchemy;
			Enchantment * asEnchantment;
			Spell * asSpell;
		} source; // 0xA0
		MagicSourceType sourceType;// 0xA4

		//
		// Other related this-call functions.
		//

		Effect * getSourceEffects();
	};
	static_assert(sizeof(MagicSourceCombo) == 0x8, "TES3::MagicSourceCombo failed size validation");

	struct MagicSourceInstance : BaseObject {
		float overrideCastChance; // 0x10
		Reference * target;
		signed char unknown_0x18;
		char padding_0x19[3];
		HashMap effects[8]; // 0x1C
		MobileProjectile * magicProjectile;
		MagicSourceCombo sourceCombo;
		unsigned int serialNumber;
		void * unknown_0xAC;
		float timestampCastBegin; // 0xB0
		SpellEffectState state;
		Reference * caster;
		Item * castingItem;
		ItemData * castingItemCondition;
		char castingItemID[32];
		char magicID[32];
		Sound * soundEffects[8];
		int unknown_0x124;
		float unknown_0x128;

		//
		// Other related this-call functions.
		//

		int getMagnitude(int effectIndex);

	};
	static_assert(sizeof(MagicSourceInstance) == 0x12C, "TES3::MagicSourceInstance failed size validation");
}

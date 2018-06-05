#pragma once

#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3Object.h"

namespace TES3 {
	namespace SpellEffectState {
		enum SpellEffectState {
			Begining = 4,
			Working = 5,
			Ending = 6,
			Retired = 7,
			WorkingFortify = 8,
			EndingFortify = 9
		};
	}

	namespace MagicSourceType {
		enum MagicSourceType {
			Spell = 0x1,
			Enchantment = 0x2,
			Alchemy = 0x3
		};
	}

	struct MagicSourceCombo {
		union {
			Object * asGeneric;
			Alchemy * asAlchemy;
			Spell * asSpell;
		} source; // 0xA0
		signed char sourceType;// 0xA4

		//
		// Other related this-call functions.
		//

		Effect * getSourceEffects();
	};
	static_assert(sizeof(MagicSourceCombo) == 0x8, "TES3::MagicSourceCombo failed size validation");

	struct MagicSourceInstance : BaseObject {
		float overrideCastChance; // 0x10
		void * unknown_0x14;
		void * unknown_0x18;
		HashMap effects[8]; // 0x1C
		void * unknown_0x9C; // Node?
		MagicSourceCombo sourceCombo;
		void * unknown_0xA8;
		void * unknown_0xAC;
		void * unknown_0xB0;
		int state; // 0xB4
		Reference * caster;
		Item * castingItem;
		ItemData * castingItemCondition;
		int unknown_0xC4;
		int unknown_0xC8;
		int unknown_0xCC;
		int unknown_0xD0;
		int unknown_0xD4;
		int unknown_0xD8;
		int unknown_0xDC;
		int unknown_0xE0;
		char text[64]; // 0xE4
		int unknown_0x124;
		float unknown_0x128;
	};
	static_assert(sizeof(MagicSourceInstance) == 0x12C, "TES3::MagicSourceInstance failed size validation");
}

#pragma once

#include "TES3Object.h"
#include "TES3Collections.h"

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

	struct SpellInstance {
		void * vTable; // 0x0
		TES3::ObjectType::ObjectType objectType; // 0x4
		void * unknown_0x8;
		void * unknown_0xC;
		float overrideCastChance; // 0x10
		void * unknown_0x14;
		void * unknown_0x18;
		HashMap effects[8]; // 0x1C
		void * unknown_0x9C; // Node?
		Spell * spell; // 0xA0
		char sourceType;// 0xA4
		void * unknown_0xA8;
		void * unknown_0xAC;
		void * unknown_0xB0;
		int spellState; // 0xB4
		void * targetReference;
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
		char spellText[64]; // 0xE4
		int unknown_0x124;
		float unknown_0x128;
	};
	static_assert(sizeof(SpellInstance) == 0x12C, "TES3::SpellInstance failed size validation");
}

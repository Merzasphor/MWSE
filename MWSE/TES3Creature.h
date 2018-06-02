#pragma once

#include "sol_forward.hpp"

#include "TES3Object.h"
#include "TES3Actor.h"
#include "TES3AIConfig.h"
#include "TES3SpellList.h"

namespace TES3 {
	struct Creature : Actor {
		struct Attributes {
			int strength;
			int intelligence;
			int willpower;
			int agility;
			int speed;
			int endurance;
			int personality;
			int luck;
		};
		struct Skills {
			int combat;
			int magic;
			int stealth;
		};
		struct Attack {
			int min;
			int max;
		};
		char * model; // 0x6C
		char * name; // 0x70
		Script * script; // 0x74
		Creature * soundGenerator; // 0x78
		int creatureType; // 0x7C
		int level; // 0x80
		Attributes attributes; // 0x84
		int health; // 0xA4
		int magicka; // 0xA8
		int fatigue; // 0xAC
		int soul; // 0xB0
		Skills skills; // 0xB4
		Attack attacks[3]; // 0xC0
		int barterGold; // 0xD8
		SpellList * spellList; // 0xDC
		void * aiPackageList; // 0xE0
		AIConfig * aiConfig; // 0xE4

		//
		// Lua interface functions.
		//

		sol::object getAttacks();

	};
	static_assert(sizeof(Creature) == 0xE8, "TES3::Creature failed size validation");

	struct CreatureInstance : Actor {
		Creature * baseCreature; // 0x6C
		Item * weapon; // 0x70
		void * sgNode_74;
		int field_78;
		void * sgNode_7C;
		int field_80;
		void * sgNode_84;
		int field_88;

		//
		// Lua interface functions.
		//

		sol::object getAttributes();
		sol::object getSkills();
		sol::object getAttacks();
	};
	static_assert(sizeof(CreatureInstance) == 0x8C, "TES3::CreatureInstance failed size validation");
}

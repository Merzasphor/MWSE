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
		char * model;
		char * name;
		Script * script;
		Creature * soundGenerator;
		int creatureType;
		int level;
		Attributes attributes;
		int health;
		int magicka;
		int fatigue;
		int soul;
		Skills skills;
		Attack attacks[3];
		int barterGold;
		SpellList * ptrSpellList;
		void * aiPackageList;
		AIConfig * aiConfig;

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

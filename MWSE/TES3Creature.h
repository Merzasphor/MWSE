#pragma once

#include "sol_forward.hpp"

#include "TES3Object.h"
#include "TES3Actor.h"
#include "TES3AIConfig.h"
#include "TES3SpellList.h"

namespace TES3 {
	struct Creature : Actor {
		char * model;
		char * name;
		Script * script;
		void * soundgen; // Maybe?
		int creatureType;
		int level;
		int attributes[8];
		int health;
		int magicka;
		int fatigue;
		int soul;
		int combatSkill;
		int magicSkill;
		int stealthSkill;
		int attack1Min;
		int attack1Max;
		int attack2Min;
		int attack2Max;
		int attack3Min;
		int attack3Max;
		int barterGold;
		SpellList * ptrSpellList;
		void * aiPackageList;
		AIConfig * aiConfig;

		//
		// Lua interface functions.
		//

		sol::object getAttributes();

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
	};
	static_assert(sizeof(CreatureInstance) == 0x8C, "TES3::CreatureInstance failed size validation");
}

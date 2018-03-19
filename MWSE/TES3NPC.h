#pragma once

#include "TES3Object.h"
#include "TES3Actor.h"
#include "TES3AIConfig.h"
#include "TES3SpellList.h"

namespace TES3 {
	struct NPC : Actor {
		struct Attributes {
			signed char strength;
			signed char intelligence;
			signed char willpower;
			signed char agility;
			signed char speed;
			signed char endurance;
			signed char personality;
			signed char luck;
		};
		struct Skills {
			signed char block;
			signed char armorer;
			signed char mediumArmor;
			signed char heavyArmor;
			signed char bluntWeapon;
			signed char longBlade;
			signed char axe;
			signed char spear;
			signed char athletics;
			signed char enchant;
			signed char destruction;
			signed char alteration;
			signed char illusion;
			signed char conjuration;
			signed char mysticism;
			signed char restoration;
			signed char alchemy;
			signed char unarmored;
			signed char security;
			signed char sneak;
			signed char acrobatics;
			signed char lightArmor;
			signed char shortBlade;
			signed char marksman;
			signed char mercantile;
			signed char speechcraft;
			signed char handToHand;
		};
		void * model; // 0x6C
		char * name; // 0x70
		Script * script; // 0x74
		void * linkedObjectIDs; // 0x78
		short level; // 0x7C
		union {
			Attributes asStruct;
			signed char asArray[8];
		} attributes; // 0x7E
		union {
			Skills asStruct;
			signed char asArray[27];
		} skills; // 0x86
		unsigned char reputation; // 0xA1
		short health; // 0xA2
		short magicka; // 0xA4
		short fatigue; // 0xA6
		signed char disposition; // 0xA8
		unsigned char factionIndex; // 0xA9
		unsigned char factionRank; // 0xAA
		char unknown_0xAB; // Padding.
		int barterGold; // 0xAC
		Race * race; // 0xB0
		Class * class_; // 0xB4
		Faction * faction; // 0xB8
		Bodypart * head; // 0xBC
		Bodypart * hair; // 0xC0
		SpellList spellList; // 0xC4
		void * aiPackageList; // 0xDC
		AIConfig aiConfig; // 0xE0

		//
		// 
		//

		Attributes* getAttributes();
		Skills* getSkills();

	};
	static_assert(sizeof(NPC) == 0xF0, "TES3::NPC failed size validation");

	struct NPCInstance : Actor {
		NPC * baseNPC; // 0x6C
		short disposition; // 0x70
		unsigned char factionIndex; // 0x72
		char unknown_0x73; // Padding.
		void * aiData; // 0x74

		//
		// 
		//

		NPC::Attributes* getAttributes();
		NPC::Skills* getSkills();

		unsigned char getReputation();
		void setReputation(unsigned char);

		void setFactionRank(unsigned char);
	};
	static_assert(sizeof(NPCInstance) == 0x78, "TES3::NPCInstance failed size validation");
}

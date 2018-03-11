#pragma once

#include "TES3Object.h"
#include "TES3Actor.h"
#include "TES3AIConfig.h"
#include "TES3SpellList.h"

namespace TES3 {
	namespace NPCFlag {
		enum NPCFlag {
			Female = 0x1,
			Essential = 0x2,
			Respawns = 0x4,
			IsBase = 0x8,
			AutoCalc = 0x10,
			BloodSkeleton = 0x400,
			BloodMetal = 0x800,
		};
	}

	namespace NPCFlagBit {
		enum NPCFlagBit {
			FemaleBit = 0,
			EssentialBit = 1,
			RespawnsBit = 2,
			IsBaseBit = 3,
			AutocalcBit = 4,
			BloodSkeletonBit = 10,
			BloodMetalBit = 11,
		};
	}

	struct NPC : Actor {
		void * model; // 0x6C
		char * name; // 0x70
		Script * script; // 0x74
		void * linkedObjectIDs; // 0x78
		short level; // 0x7C
		unsigned char attributes[8]; // 0x7E
		unsigned char skills[27]; // 0x86
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
	};
	static_assert(sizeof(NPC) == 0xF0, "TES3::NPC failed size validation");

	struct NPCInstance : Actor {
		NPC * baseNPC; // 0x6C
		short disposition; // 0x70
		unsigned char factionIndex; // 0x72
		char unknown_0x73; // Padding.
		void * aiData; // 0x74
	};
	static_assert(sizeof(NPCInstance) == 0x78, "TES3::NPCInstance failed size validation");
}

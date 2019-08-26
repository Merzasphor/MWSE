#pragma once

#include "TES3Defines.h"

#include "TES3Actor.h"
#include "TES3AIConfig.h"
#include "TES3SpellList.h"

namespace TES3 {
	namespace ActorFlagNPC {
		typedef unsigned int value_type;

		enum Flag : value_type {
			Female = 0x1,
			Essential = 0x2,
			Respawn = 0x4,
			IsBase = 0x8,
			AutoCalc = 0x10,
			BloodSkeleton = 0x400,
			BloodMetal = 0x800,
		};

		enum FlagBit {
			FemaleBit = 0,
			EssentialBit = 1,
			RespawnBit = 2,
			IsBaseBit = 3,
			AutoCalcBit = 4,
			BloodSkeletonBit = 10,
			BloodMetalBit = 11,
		};
	}

	struct NPCBase : Actor {
		// No data, this is only used for shared functions.

		//
		// Related this-call functions.
		//

		int getBaseDisposition(bool);

	};

	struct NPC : NPCBase {
		void * model; // 0x6C
		char * name; // 0x70
		Script * script; // 0x74
		void * linkedObjectIDs; // 0x78
		short level; // 0x7C
		signed char attributes[8]; // 0x7E
		signed char skills[27]; // 0x86
		unsigned char reputation; // 0xA1
		short health; // 0xA2
		short magicka; // 0xA4
		short fatigue; // 0xA6
		signed char baseDisposition; // 0xA8
		unsigned char factionIndex; // 0xA9
		unsigned char factionRank; // 0xAA
		char unknown_0xAB; // Padding.
		int barterGold; // 0xAC
		Race * race; // 0xB0
		Class * class_; // 0xB4
		Faction * faction; // 0xB8
		BodyPart * head; // 0xBC
		BodyPart * hair; // 0xC0
		SpellList spellList; // 0xC4
		void * aiPackageList; // 0xDC
		AIConfig aiConfig; // 0xE0

	};
	static_assert(sizeof(NPC) == 0xF0, "TES3::NPC failed size validation");

	struct NPCInstance : NPCBase {
		NPC * baseNPC; // 0x6C
		short baseDisposition; // 0x70
		unsigned char factionIndex; // 0x72
		char unknown_0x73; // Padding.
		AIPackageConfig * aiPackageConfig; // 0x74

		//
		// Related this-call functions.
		//

		int getDisposition(bool clamp = false);

		//
		// Custom functions.
		//

		unsigned char getReputation();
		void setReputation(unsigned char);

		short getBaseDisposition();
		void setBaseDisposition(short);

		void setFactionRank(unsigned char);
	};
	static_assert(sizeof(NPCInstance) == 0x78, "TES3::NPCInstance failed size validation");
}

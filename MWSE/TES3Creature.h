#pragma once

#include "sol_forward.hpp"

#include "TES3Defines.h"

#include "TES3Actor.h"

namespace TES3 {
	namespace ActorFlagCreature {
		typedef unsigned int value_type;

		enum Flag : value_type {
			Biped = 0x1,
			Respawn = 0x2,
			WeaponAndShield = 0x4,
			IsBase = 0x8,
			Swims = 0x10,
			Flies = 0x20,
			Walks = 0x40,
			Essential = 0x80,
			SkeletonBlood = 0x400,
			MetalBlood = 0x800,

			DefaultFlags = Walks | IsBase,
		};

		enum FlagBit {
			BipedBit = 0,
			RespawnBit = 1,
			WeaponAndShieldBit = 2,
			IsBaseBit = 3,
			SwimsBit = 4,
			FliesBit = 5,
			WalksBit = 6,
			EssentialBit = 7,
			SkeletonBloodBit = 10,
			MetalBloodBit = 11,
		};
	}

	namespace CreatureType {
		enum CreatureType {
			Normal,
			Daedra,
			Undead,
			Humanoid
		};
	}

	namespace CreatureSkill {
		enum CreatureSkill {
			Combat,
			Magic,
			Stealth
		};
	}

	struct Creature : Actor {
		char * model; // 0x6C
		char * name; // 0x70
		Script * script; // 0x74
		Creature * soundGenerator; // 0x78
		int creatureType; // 0x7C
		int level; // 0x80
		int attributes[8]; // 0x84
		int health; // 0xA4
		int magicka; // 0xA8
		int fatigue; // 0xAC
		int soul; // 0xB0
		int skills[3]; // 0xB4
		Range<int> attacks[3]; // 0xC0
		int barterGold; // 0xD8
		SpellList * spellList; // 0xDC
		void * aiPackageList; // 0xE0
		AIConfig * aiConfig; // 0xE4

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
		AIPackageConfig * aiPackageConfig; // 0x88
	};
	static_assert(sizeof(CreatureInstance) == 0x8C, "TES3::CreatureInstance failed size validation");
}

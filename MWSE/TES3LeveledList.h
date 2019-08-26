#pragma once

#include "TES3Defines.h"

#include "TES3Object.h"

namespace TES3 {
	namespace LeveledListFlags {
		typedef unsigned int value_type;

		enum Flags : value_type {
			CalculateFromAllLevels = 0x1,
			CalculateForEachItem = 0x2
		};
	}

	struct LeveledListNode {
		Object * object;
		short levelRequirement;
	};
	static_assert(sizeof(LeveledListNode) == 0x8, "TES3::LeveledListNode failed size validation");

	struct LeveledCreature : PhysicalObject {
		ActorAnimationData * animationData; // 0x30 // Why?
		Iterator<LeveledListNode> * itemList; // 0x34
		int itemCount; // 0x38
		mwse::bitset32 flags; // 0x3C
		signed char chanceForNothing; // 0x40

		//
		// Other related this-call functions.
		//

		Object * resolve();

	};
	static_assert(sizeof(LeveledCreature) == 0x44, "TES3::LeveledCreature failed size validation");

	struct LeveledItem : PhysicalObject {
		Iterator<LeveledListNode> * itemList; // 0x30
		int itemCount; // 0x34
		mwse::bitset32 flags; // 0x38
		signed char chanceForNothing; // 0x3C

		//
		// Other related this-call functions.
		//

		Object * resolve();

	};
	static_assert(sizeof(LeveledItem) == 0x40, "TES3::LeveledItem failed size validation");
}

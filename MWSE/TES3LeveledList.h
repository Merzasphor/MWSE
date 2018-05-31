#pragma once

#include "TES3Object.h"

namespace TES3 {
	namespace LeveledListFlags {
		enum LeveledListFlags {
			CalculateFromAllLevels = 0x1,
			CalculateForEachItem = 0x2
		};
	}

	struct LeveledListNode {
		Object * object;
		short levelRequirement;
	};
	static_assert(sizeof(LeveledListNode) == 0x8, "TES3::LeveledListNode failed size validation");

	struct LeveledList : PhysicalObject {
		Iterator<LeveledListNode> * itemList; // 0x30
		int itemCount; // 0x34
		unsigned int flags; // 0x38
		signed char chanceForNothing; // 0x3C

		//
		// Other related this-call functions.
		//

		Object * resolve();

	};
	static_assert(sizeof(LeveledList) == 0x40, "TES3::LeveledList failed size validation");
}

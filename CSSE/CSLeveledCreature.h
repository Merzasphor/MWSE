#pragma once

#include "CSLeveledList.h"

#include "NIIteratedList.h"

namespace se::cs {
	struct LeveledCreature : LeveledList {
		int unknown_0x48;
		NI::IteratedList<Node*>* list; // 0x4C
		size_t listSize; // 0x50
		BYTE leveledFlags; // 0x54

		bool getCalculateFromAllLevelsLessThanEqualToPCLevel() const;
	};
	static_assert(sizeof(LeveledCreature) == 0x58, "LeveledCreature failed size validation");
}

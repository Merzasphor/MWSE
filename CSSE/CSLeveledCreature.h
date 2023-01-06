#pragma once

#include "CSPhysicalObject.h"

#include "NIIteratedList.h"

namespace se::cs {
	struct LeveledCreature : PhysicalObject {
		int unknown_0x48;
		NI::IteratedList<void*>* list; // 0x4C
		size_t listSize; // 0x50
		BYTE leveledFlags; // 0x54

		bool getCalculateFromAllLevelsLessThanEqualToPCLevel() const;
	};
	static_assert(sizeof(LeveledCreature) == 0x58, "LeveledCreature failed size validation");
}

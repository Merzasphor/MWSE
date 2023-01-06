#pragma once

#include "CSPhysicalObject.h"

#include "NIIteratedList.h"

namespace se::cs {
	struct LeveledItem : PhysicalObject {
		NI::IteratedList<void*>* list; // 0x48
		size_t listSize; // 0x4C
		BYTE leveledFlags; // 0x50

		bool getCalculateFromEachItem() const;
		bool getCalculateFromAllLevelsLessThanEqualToPCLevel() const;
	};
	static_assert(sizeof(LeveledItem) == 0x54, "LeveledItem failed size validation");
}

#include "CSLeveledItem.h"

namespace se::cs {
	bool LeveledItem::getCalculateFromEachItem() const {
		return leveledFlags & 1;
	}

	bool LeveledItem::getCalculateFromAllLevelsLessThanEqualToPCLevel() const {
		return leveledFlags & 2;
	}
}

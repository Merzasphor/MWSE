#include "CSLeveledCreature.h"

namespace se::cs {
	bool LeveledCreature::getCalculateFromAllLevelsLessThanEqualToPCLevel() const {
		return leveledFlags & 1;
	}
}

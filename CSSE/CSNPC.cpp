#include "CSNPC.h"

#include "CSFaction.h"

namespace se::cs {
	const char* NPC::getFactionRankName() const {
		auto faction = getFaction();
		if (faction == nullptr || factionRank == -1) {
			return "";
		}
		return faction->rankNames[factionRank];
	}
}

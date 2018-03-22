#include "TES3NPC.h"

namespace TES3 {
	unsigned char NPCInstance::getReputation() {
		return baseNPC->reputation;
	}

	void NPCInstance::setReputation(unsigned char value) {
		baseNPC->reputation = value;
	}

	void NPCInstance::setFactionRank(unsigned char value) {
		baseNPC->factionRank = value;
	}

}

#include "TES3NPC.h"

#define TES3_NPC_getDisposition 0x4DA330

namespace TES3 {
	float NPCBase::getDisposition(bool clamp = true) {
		return reinterpret_cast<float(__thiscall *)(NPCBase*, signed char)>(TES3_NPC_getDisposition)(this, clamp);
	}

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

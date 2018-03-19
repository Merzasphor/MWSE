#include "TES3NPC.h"

namespace TES3 {
	NPC::Attributes* NPC::getAttributes() {
		return &attributes.asStruct;
	}

	NPC::Skills* NPC::getSkills() {
		return &skills.asStruct;
	}

	NPC::Attributes* NPCInstance::getAttributes() {
		return &baseNPC->attributes.asStruct;
	}

	NPC::Skills* NPCInstance::getSkills() {
		return &baseNPC->skills.asStruct;
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

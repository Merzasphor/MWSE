#include "TES3Faction.h"

namespace TES3 {
	char * Faction::getName() {
		return name;
	}

	void Faction::setName(const char* value) {
		if (value != NULL && strlen(value) < 32) {
			strcpy(name, value);
		}
	}

	bool Faction::getMembershipFlag(unsigned int flag) {
		return (playerMembershipFlags & flag) != 0;
	}

	void Faction::setMembershipFlag(unsigned int flag, bool set) {
		if (set) {
			playerMembershipFlags |= flag;
		}
		else {
			playerMembershipFlags &= ~flag;
		}
	}
}
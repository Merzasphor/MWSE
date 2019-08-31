#include "TES3Faction.h"

namespace TES3 {
	int Faction::getEffectivePlayerRank() {
		if (getMembershipFlag(FactionMembershipFlag::PlayerJoined)) {
			return playerRank;
		}

		return -1;
	}

	char * Faction::getFactionId() {
		return objectID;
	}

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

	void Faction::setEffectivePlayerRank(int rank) {
		if (rank < 0) {
			setMembershipFlag(FactionMembershipFlag::PlayerJoined, false);
			playerRank = -1;
		}
		else {
			setMembershipFlag(FactionMembershipFlag::PlayerJoined, true);
			playerRank = rank;
		}
	}
}
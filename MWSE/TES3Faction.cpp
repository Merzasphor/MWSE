#include "TES3Faction.h"

namespace TES3 {
	std::reference_wrapper<int[2]> Faction::Rank::getRequiredAttributeValues() {
		return std::ref(reqAttributes);
	}

	std::reference_wrapper<int[2]> Faction::Rank::getRequiredSkillValues() {
		return std::ref(reqSkills);
	}

	int Faction::getEffectivePlayerRank() const {
		if (getMembershipFlag(FactionMembershipFlag::PlayerJoined)) {
			return playerRank;
		}

		return -1;
	}

	char * Faction::getObjectID() {
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

	bool Faction::getMembershipFlag(unsigned int flag) const {
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

	bool Faction::getPlayerJoined() const {
		return getMembershipFlag(TES3::FactionMembershipFlag::PlayerJoined);
	}

	void Faction::setPlayerJoined(bool value) {
		setMembershipFlag(TES3::FactionMembershipFlag::PlayerJoined, value);
	}

	bool Faction::getPlayerExpelled() const {
		return getMembershipFlag(TES3::FactionMembershipFlag::PlayerExpelled);
	}

	void Faction::setPlayerExpelled(bool value) {
		setMembershipFlag(TES3::FactionMembershipFlag::PlayerExpelled, value);
	}

	std::reference_wrapper<int[2]> Faction::getAttributes() {
		return std::ref(attributes);
	}

	std::reference_wrapper<int[7]> Faction::getSkills() {
		return std::ref(skills);
	}

	std::reference_wrapper<Faction::Rank[10]> Faction::getRanks() {
		return std::ref(ranks);
	}
}
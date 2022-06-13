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

	const char* Faction::getRankName(size_t rank) const {
		return rankNames[std::clamp(rank, 0U, 10U)];
	}

	void Faction::setRankName(size_t rank, const char* name) {
		if (rank < 0 || rank > 9) {
			throw std::invalid_argument("Rank must be between inclusive values 0 and 9.");
		}
		else if (strnlen_s(name, 32) > 31) {
			throw std::invalid_argument("Name must not be more than 31 characters.");
		}
		strncpy_s(rankNames[rank], name, 32);
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

	bool Faction::getReactionWithFaction(const Faction* faction, int& out_reaction) const {
		for (const auto& itt : reactions) {
			if (itt->faction == faction) {
				out_reaction = itt->reaction;
				return true;
			}
		}
		return false;
	}

	sol::optional<int> Faction::getReactionWithFaction_lua(const Faction* faction) const {
		int reaction = 0;
		if (getReactionWithFaction(faction, reaction)) {
			return reaction;
		}
		return {};
	}

	const auto TES3_Faction_getLowestJoinedReaction = reinterpret_cast<int(__thiscall*)(const Faction*, Faction**)>(0x4AD5E0);
	int Faction::getLowestJoinedReaction(Faction** out_faction) const {
		return TES3_Faction_getLowestJoinedReaction(this, out_faction);
	}

	sol::optional<std::tuple<int, Faction*>> Faction::getLowestJoinedReaction_lua() const {
		Faction* faction = nullptr;
		auto reaction = getLowestJoinedReaction(&faction);
		if (faction) {
			return { { reaction, faction } };
		}
		return {};
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

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::Faction)

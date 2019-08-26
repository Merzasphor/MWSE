#pragma once

#include "sol_forward.hpp"

#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3Object.h"

namespace TES3 {
	namespace FactionMembershipFlag {
		typedef unsigned int value_type;

		enum Flag : value_type {
			PlayerJoined = 0x1,
			PlayerExpelled = 0x2
		};
	}
	struct Faction : BaseObject {
		struct Rank {
			int reqAttributes[2];
			int reqSkills[2];
			int reputation;
		};
		struct ReactionNode {
			Faction * faction;
			int reaction;
		};
		char objectID[32]; // 0x10
		char name[32]; // 0x30
		char rankNames[10][32]; // 0x50
		long attributes[2]; // 0x190
		Rank ranks[10]; // 0x198
		long skills[7]; // 0x260
		int unknown_0x27C;
		Iterator<ReactionNode> reactions; // 0x280
		int playerRank; // 0x294
		int playerReputation; // 0x298
		mwse::bitset32 playerMembershipFlags; // 0x29C

		//
		// Custom functions.
		//

		char * getName();
		void setName(const char*);

		bool getMembershipFlag(unsigned int);
		void setMembershipFlag(unsigned int, bool);

		int getEffectivePlayerRank();
		void setEffectivePlayerRank(int rank);

	};
	static_assert(sizeof(Faction::Rank) == 0x14, "TES3::Faction::Rank failed size validation");
	static_assert(sizeof(Faction::ReactionNode) == 0x8, "TES3::Faction::ReactionNode failed size validation");
	static_assert(sizeof(Faction) == 0x2A0, "TES3::Faction failed size validation");
}

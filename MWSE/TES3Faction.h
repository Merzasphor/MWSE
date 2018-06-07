#pragma once

#include "sol_forward.hpp"

#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3Object.h"

namespace TES3 {
	struct Faction : BaseObject {
		struct Rank {
			long reqAttributes[2];
			long reqSkills[2];
			long reputation;
		};
		struct ReactionNode {
			Faction * faction;
			long reaction;
		};
		char objectID[32]; // 0x10
		char name[32]; // 0x30
		char rankNames[10][32]; // 0x50
		long attributes[2]; // 0x190
		Rank ranks[10]; // 0x198
		long skills[7]; // 0x260
		int unknown_0x27C;
		Iterator<ReactionNode> reactions; // 0x280
		int unknown_0x294;
		int unknown_0x298;
		int unknown_0x29C;

		//
		// Custom functions.
		//

		char * getName();
		void setName(const char*);

	};
	static_assert(sizeof(Faction::Rank) == 0x14, "TES3::Faction::Rank failed size validation");
	static_assert(sizeof(Faction::ReactionNode) == 0x8, "TES3::Faction::ReactionNode failed size validation");
	static_assert(sizeof(Faction) == 0x2A0, "TES3::Faction failed size validation");
}

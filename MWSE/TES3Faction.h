#pragma once

#include "ObjectTypes.h"

#include "TES3Sound.h"

namespace TES3 {
	struct Faction_vTable {

	};

	struct Faction {
		Faction_vTable * vTable;
		ObjectType::ObjectType objectType;
		int unknown_0x08;
		int unknown_0x0C;
		char objectID[32]; // 0x10
		char name[32]; // 0x30
		char ranks[10][32]; // 0x50
		int unknown_0x190[68];
	};
	static_assert(sizeof(Faction) == 0x2A0, "TES3::Faction failed size validation");
}

#pragma once

#include "TES3Object.h"

namespace TES3 {
	struct Faction : BaseObject {
		char objectID[32]; // 0x10
		char name[32]; // 0x30
		char ranks[10][32]; // 0x50
		int unknown_0x190[68];
	};
	static_assert(sizeof(Faction) == 0x2A0, "TES3::Faction failed size validation");
}

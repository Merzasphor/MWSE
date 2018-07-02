#pragma once

#include "TES3Defines.h"

#include "TES3MobileActor.h"
#include "TES3Statistic.h"

namespace TES3 {
	struct MobileCreature : MobileActor {
		CreatureInstance * creatureInstance; // 0x3B0
		Statistic combatSkill; // 0x3B4
		Statistic magicSkill; // 0x3C0
		Statistic stealthSkill; // 0x3C

		//
		// Other related this-call functions.
		//

		float calculateWalkSpeed();
	};
	static_assert(sizeof(MobileCreature) == 0x3D8, "TES3::MobileCreature failed size validation");
}

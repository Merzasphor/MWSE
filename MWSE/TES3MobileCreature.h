#pragma once

#include "TES3Defines.h"

#include "TES3MobileActor.h"
#include "TES3Statistic.h"

namespace TES3 {

	namespace CreatureSkillID {
		enum CreatureSkillID {
			Combat = 0,
			Magic = 1,
			Stealth = 2,

			FirstSkill = Combat,
			LastSkill = Stealth
		};
	}

	struct MobileCreature : MobileActor {
		CreatureInstance * creatureInstance; // 0x3B0
		Statistic skills[3]; // 0x3B4

		//
		// Other related this-call functions.
		//

		float calculateWalkSpeed();
	};
	static_assert(sizeof(MobileCreature) == 0x3D8, "TES3::MobileCreature failed size validation");
}

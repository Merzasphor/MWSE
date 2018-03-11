#pragma once

#include "TES3Object.h"
#include "TES3MobileActor.h"
#include "TES3Statistic.h"

namespace TES3 {
	struct MobileNPC : MobileActor {
		SkillStatistic skills[27]; // 0x3B0
		NPCInstance * npcInstance; // 0x560
		char unknown_0x564;
		char flagForceSneak; // 0x565
		char flagForceRun; // 0x566
		char flagForceJump; // 0x567
		char flagForceMoveJump; // 0x568
		char unknown_0x569; // Undefined.
		char unknown_0x56A; // Undefined.
		char unknown_0x56B; // Undefined.
	};
	static_assert(sizeof(MobileNPC) == 0x56C, "TES3::MobileNPC failed size validation");
}

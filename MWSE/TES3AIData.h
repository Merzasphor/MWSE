#pragma once

#include "TES3Defines.h"

namespace TES3 {
	struct AIData {
		int unknown_0x0;
		MobileActor * mobileActor; // 0x4
		int unknown_0x8;
		AIPackage * packages[32]; // 0xC
		int nextOpenPackageIndex; // 0x8C
		int currentPackageIndex; // 0x90
		int unknown_0x94;

		//
		// Other related this-call functions.
		//

		AIPackage * getActivePackage();
	};
	static_assert(sizeof(AIData) == 0x98, "TES3::AIData failed size validation");
}

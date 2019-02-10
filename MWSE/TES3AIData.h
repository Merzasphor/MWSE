#pragma once

#include "TES3Defines.h"
#include "TES3Vectors.h"

namespace TES3 {
	struct AIData {
		AIPackageConfig * config; // 0x0
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

	namespace AIPackageConfigType {
		enum AIPackageConfigType {
			Travel = 0x1,
			Wander = 0x2,
			Escort = 0x3,
			Follow = 0x4,
			Activate = 0x5,
		};
	}

	struct AIPackageConfig {
		int type; // 0x0
	};
	static_assert(sizeof(AIPackageConfig) == 0x4, "TES3::AIPackageConfig failed size validation");
}

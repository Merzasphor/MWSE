#pragma once

#include "TES3Defines.h"
#include "TES3Vectors.h"

namespace TES3 {
	struct AIPlanner {
		AIPackageConfig * currentPackageConfig; // 0x0
		MobileActor * mobileActor; // 0x4
		int counter_0x8;
		AIPackage * packages[32]; // 0xC
		short indexActivePackage; // 0x8C
		short pad_8E; // 0x8E
		int countPackages; // 0x90
		float unknown_0x94;

		//
		// Other related this-call functions.
		//

		AIPackage * getActivePackage();

		//
		// Custom functions.
		//

		std::reference_wrapper<AIPackage* [32]> getPackages();

	};
	static_assert(sizeof(AIPlanner) == 0x98, "TES3::AIPlanner failed size validation");
}

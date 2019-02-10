#pragma once

#include "TES3Defines.h"

#include "TES3AIData.h"
#include "TES3AIPackage.h"
#include "TES3Vectors.h"

namespace TES3 {
	struct AIPackageTravel : AIPackage {
		struct Config : AIPackageConfig {
			Vector3 position; // 0x4
			bool reset; // 0x10
		};
		Vector3 destination; // 0x3C
		int unknown_0x48;
		Vector3 unknown_0x4C;
		void * pathingData; // 0x58
	};
	static_assert(sizeof(AIPackageTravel) == 0x5C, "TES3::AIPackageTravel failed size validation");
	static_assert(sizeof(AIPackageTravel::Config) == 0x14, "TES3::AIPackageTravel::Config failed size validation");
}

#pragma once

#include "TES3Object.h"
#include "TES3AIPackage.h"
#include "TES3Vectors.h"

namespace TES3 {
	struct AIPackageTravel : AIPackage {
		Vector3 destination; // 0x3C
		int unknown_0x48;
		Vector3 unknown_0x4C;
		void * pathingData; // 0x58
	};
	static_assert(sizeof(AIPackageTravel) == 0x5C, "TES3::AIPackageTravel failed size validation");
}

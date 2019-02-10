#pragma once

#include "TES3Defines.h"

#include "TES3AIData.h"
#include "TES3AIPackage.h"
#include "TES3Vectors.h"

namespace TES3 {
	struct AIPackageEscort : AIPackage {
		struct Config : AIPackageConfig {
			Vector3 destination; // 0x4
			unsigned char duration; // 0x10
			Actor * actor; // 0x14;
			Cell * cell; // 0x18
			bool reset; // 0x1C
		};
		Vector3 destination; // 0x3C
		int unknown_0x48;
		int unknown_0x4C;
	};
	static_assert(sizeof(AIPackageEscort) == 0x50, "TES3::AIPackageEscort failed size validation");
	static_assert(sizeof(AIPackageEscort::Config) == 0x20, "TES3::AIPackageEscort::Config failed size validation");
}

#pragma once

#include "TES3Defines.h"

#include "TES3AIPackage.h"
#include "TES3Vectors.h"

namespace TES3 {
	struct AIPackageEscort : AIPackage {
		Vector3 destination; // 0x3C
		int unknown_0x48;
		int unknown_0x4C;
	};
	static_assert(sizeof(AIPackageEscort) == 0x50, "TES3::AIPackageEscort failed size validation");
}

#pragma once

#include "TES3Object.h"
#include "TES3AIPackage.h"

namespace TES3 {
	struct AIPackageActivate : AIPackage {
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		int unknown_0x48;
		int unknown_0x4C;
		Reference * activateTarget; // 0x50
	};
	static_assert(sizeof(AIPackageActivate) == 0x54, "TES3::AIPackageActivate failed size validation");
}

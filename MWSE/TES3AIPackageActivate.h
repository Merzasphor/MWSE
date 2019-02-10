#pragma once

#include "TES3Defines.h"

#include "TES3AIData.h"
#include "TES3AIPackage.h"

namespace TES3 {
	struct AIPackageActivate : AIPackage {
		struct Config : AIPackageConfig {
			Reference * target; // 0x4
			bool reset; // 0x8
		};
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		int unknown_0x48;
		int unknown_0x4C;
		Reference * activateTarget; // 0x50
	};
	static_assert(sizeof(AIPackageActivate) == 0x54, "TES3::AIPackageActivate failed size validation");
	static_assert(sizeof(AIPackageActivate::Config) == 0xC, "TES3::AIPackageActivate::Config failed size validation");
}

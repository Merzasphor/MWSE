#pragma once

#include "TES3Object.h"
#include "TES3AIPackage.h"
#include "TES3Vectors.h"

namespace TES3 {
	struct AIPackageWander : AIPackage {
		struct IdleNode {
			unsigned char index; // 0x0
			char unknown_0x1;
			char unknown_0x2;
			char unknown_0x3;
			int chance;  // 0x4
		};
		Vector3 unknown_0x3C;
		int unknown_0x48;
		short unknown_0x4C;
		signed char unknown_0x4E;
		signed char unknown_0x4F;
		Reference * activationTarget; // 0x50
		int unknown_0x54;
		IdleNode unknown_0x58[8];
	};
	static_assert(sizeof(AIPackageWander::IdleNode) == 0x8, "TES3::AIPackageWander::IdleNode failed size validation");
	static_assert(sizeof(AIPackageWander) == 0x98, "TES3::AIPackageWander failed size validation");
}

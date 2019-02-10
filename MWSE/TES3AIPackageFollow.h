#pragma once

#include "TES3Defines.h"

#include "TES3AIData.h"
#include "TES3AIPackage.h"
#include "TES3Vectors.h"

namespace TES3 {
	struct AIPackageFollow : AIPackage {
		struct Config : AIPackageConfig {
			Vector3 destination; // 0x4
			unsigned char duration; // 0x10
			Actor * actor; // 0x14;
			Cell * cell; // 0x18
			bool reset; // 0x1C
		};
		Vector3 destination; // 0x3C
		int unknown_0x48;
		unsigned char unknown_0x4C;
		unsigned char unknown_0x4D;
		unsigned char unknown_0x4E;
		unsigned char unknown_0x4F;
		int unknown_0x50;
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C;
		int unknown_0x60;
		float followDistance; // 0x64
	};
	static_assert(sizeof(AIPackageFollow) == 0x68, "TES3::AIPackageFollow failed size validation");
	static_assert(sizeof(AIPackageFollow::Config) == 0x20, "TES3::AIPackageFollow::Config failed size validation");
}

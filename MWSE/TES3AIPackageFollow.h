#pragma once

#include "TES3Defines.h"

#include "TES3AIPackage.h"
#include "TES3Vectors.h"

namespace TES3 {
	struct AIPackageFollow : AIPackage {
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
}

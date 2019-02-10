#pragma once

#include "TES3Defines.h"
#include "TES3Vectors.h"

namespace TES3 {
	struct AIData {
		AIPackageConfig * config; // 0x0
		MobileActor * mobileActor; // 0x4
		int unknown_0x8;
		AIPackage * packages[32]; // 0xC
		int nextOpenPackageIndex; // 0x8C
		int currentPackageIndex; // 0x90
		int unknown_0x94;

		//
		// Other related this-call functions.
		//

		AIPackage * getActivePackage();
	};
	static_assert(sizeof(AIData) == 0x98, "TES3::AIData failed size validation");

	namespace AIPackageConfigType {
		enum AIPackageConfigType {
			Travel = 0x1,
		};
	}

	struct AIPackageConfig {
		int type; // 0x0
		Vector3 position; // 0x4
		bool reset; // 0x10
		bool unknown_0x11;
		bool unknown_0x12;
		bool unknown_0x13;
	};
	static_assert(sizeof(AIPackageConfig) == 0x14, "TES3::AIPackageConfig failed size validation");

	struct AIPackageConfigExtended : AIPackageConfig {
		Actor * actor; // 0x14
		int unknown_0x18;
		bool unknown_0x1C;
		bool unknown_0x1D;
		bool unknown_0x1E;
		bool unknown_0x1F;
	};
	static_assert(sizeof(AIPackageConfigExtended) == 0x20, "TES3::AIPackageConfigExtended failed size validation");
}

#pragma once

#include "TES3Defines.h"

#include "TES3Vectors.h"

namespace TES3 {
	struct AIPackageVirtualTable {
		AIPackage* (__thiscall * deleting)(AIPackage*, bool); // 0x0
		void (__thiscall * simulate)(AIPackage*); // 0x4
		bool (__thiscall * movement)(AIPackage*); // 0x8
		bool (__thiscall * initialize)(AIPackage*); // 0xC
		void (__thiscall * cleanup)(AIPackage*); // 0x10
	};
	static_assert(sizeof(AIPackageVirtualTable) == 0x14, "TES3::AIPackage_vTable failed size validation");

	struct AIPackage {
		AIPackageVirtualTable * vTable; // 0x0
		char unknown_0x4;
		bool moving; // 0x5
		char unknown_0x6[2];
		float startGameHour; // 0x8
		void * targetActor; // 0xC
		int packageType; // 0x10
		void * unknown_0x14; // Pointer to a vector?
		short duration; // 0x18
		char unknown_0x19[2];
		int distance; // 0x1C
		int hourOfDay; // 0x20
		Vector3 targetPosition; // 0x24
		bool done; // 0x30
		bool started; // 0x31
		bool reset; // 0x32
		bool finalized; // 0x33
		MobileActor * owningActor; // 0x34
		Cell * destinationCell; // 0x38

		//
		// vTable accessor functions.
		//

		void simulate();
		bool movement();
		bool initialize();
		void cleanup();

	};
	static_assert(sizeof(AIPackage) == 0x3C, "TES3::AIPackage failed size validation");
}

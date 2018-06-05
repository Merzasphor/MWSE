#pragma once

#include "TES3Defines.h"

#include "TES3Vectors.h"

namespace TES3 {
	struct AIPackage {
		void * vTable; // 0x0
		char unknown_0x4;
		unsigned char moving; // 0x5
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
		char done; // 0x30
		char started; // 0x31
		char reset; // 0x32
		char finalized; // 0x33
		void * owningActor; // 0x34
		Cell * destinationCell; // 0x38
	};
	static_assert(sizeof(AIPackage) == 0x3C, "TES3::AIPackage failed size validation");
}

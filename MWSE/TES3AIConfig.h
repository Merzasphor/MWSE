#pragma once

#include "TES3Attachment.h"
#include "TES3Collections.h"

namespace TES3 {
	struct AIConfig {
		short hello; // 0x0
		unsigned char fight; // 0x2
		unsigned char flee; // 0x3
		unsigned char alarm; // 0x4
		char unknown_0x5[3];
		mwse::bitset32 merchantFlags; // 0x8
		Iterator<TravelDestination> * travelDestinations; // 0xC
	};
	static_assert(sizeof(AIConfig) == 0x10, "TES3::AIConfig failed size validation");
}

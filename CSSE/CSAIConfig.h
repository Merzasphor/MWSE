#pragma once

#include "NIIteratedList.h"

namespace se::cs {
	struct AIConfig {
		short hello; // 0x0
		byte fight; // 0x2
		byte flee; // 0x3
		byte alarm; // 0x4
		unsigned int merchantFlags; // 0x8
		NI::IteratedList<void*>* travelDestinations; // 0xC
	};
	static_assert(sizeof(AIConfig) == 0x10, "AIConfig failed size validation");
}

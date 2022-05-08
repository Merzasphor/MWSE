#pragma once

#include "TES3Defines.h"

namespace TES3 {
	struct WearablePart {
		int bodypartID; // 0x0
		BodyPart * male; // 0x4
		BodyPart * female; // 0x8

		WearablePart();
	};
	static_assert(sizeof(WearablePart) == 0xC, "TES3::WearablePart failed size validation");
}

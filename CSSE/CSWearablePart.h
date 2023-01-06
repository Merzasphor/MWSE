#pragma once

#include "CSDefines.h"

namespace se::cs {
	struct WearablePart {
		int partID; // 0x0
		BodyPart* male; // 0x4
		BodyPart* female; // 0x8
	};
	static_assert(sizeof(WearablePart) == 0xC, "WearablePart failed size validation");
}

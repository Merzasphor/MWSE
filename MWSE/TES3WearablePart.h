#pragma once

namespace TES3 {
	struct WearablePart {
		int bodypartID; // 0x0
		BodyPart * male; // 0x4
		BodyPart * female; // 0x8
	};
	static_assert(sizeof(WearablePart) == 0xC, "TES3::WearablePart failed size validation");
}

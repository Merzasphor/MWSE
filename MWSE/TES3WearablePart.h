#pragma once

namespace TES3 {
	struct WearablePart {
		int bodyPartID;
		void * male;
		void * female;
	};
	static_assert(sizeof(WearablePart) == 0xC, "TES3::WearablePart failed size validation");
}

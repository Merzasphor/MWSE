#pragma once

#include "NIVector3.h"

namespace NI {
	struct BoundingBox {
		Vector3 min; // 0x0
		Vector3 max; // 0xC

		void invalidate();
	};
	static_assert(sizeof(BoundingBox) == 0x18, "NI::BoundingBox failed size validation");
}

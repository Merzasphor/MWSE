#pragma once

#include "NIVector3.h"

namespace NI {
	struct Bound {
		Vector3 center; // 0x0
		float radius; // 0xC
	};
	static_assert(sizeof(Bound) == 0x10, "NI::Bound failed size validation");
}

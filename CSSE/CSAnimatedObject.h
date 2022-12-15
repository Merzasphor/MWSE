#pragma once

#include "CSPhysicalObject.h"

namespace se::cs {
	struct AnimatedObject : PhysicalObject {
		int unknown_0x48;
	};
	static_assert(sizeof(AnimatedObject) == 0x4C, "AnimatedObject failed size validation");
}

#pragma once

#include "CSPhysicalObject.h"

namespace se::cs {
	struct Static : PhysicalObject {
		const char* unknown_0x48;
	};
	static_assert(sizeof(Static) == 0x4C, "TES3::Static failed size validation");
}

#pragma once

#include "TES3Object.h"

namespace TES3 {
	struct Static : PhysicalObject {
		char * model;
	};
	static_assert(sizeof(Static) == 0x34, "TES3::Static failed size validation");
}

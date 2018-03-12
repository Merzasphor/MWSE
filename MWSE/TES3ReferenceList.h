#pragma once

#include "TES3Reference.h"
#include "TES3Cell.h"
#include "TES3Collections.h"

namespace TES3 {
	struct ReferenceList : LinkedList<Reference> {
		Cell * cell;
	};
	static_assert(sizeof(ReferenceList) == 0x10, "TES3::ReferenceList failed size validation");
}

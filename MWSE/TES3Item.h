#pragma once

#include "TES3Defines.h"

#include "TES3Object.h"

namespace TES3 {
	// Dummy structure we mostly use for Lua casting.
	struct Item : PhysicalObject {
		//
		// Custom functions.
		//

		ItemData * createItemData();

	};
	static_assert(sizeof(Item) == 0x30, "TES3::Item failed size validation");
}

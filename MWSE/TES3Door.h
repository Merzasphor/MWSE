#pragma once

#include "TES3Object.h"

namespace TES3 {
	struct Door : PhysicalObject {
		int unknown_0x30;
		char name[32]; // 0x34
		char model[32]; // 0x54
		int unknown_0x74;
		void * openSound;
		void * closeSound;
	};
	static_assert(sizeof(Door) == 0x80, "TES3::Door failed size validation");
}

#pragma once

#include "TES3Defines.h"

#include "TES3Object.h"

namespace TES3 {
	struct DialogueInfo : BaseObject {
		void * unknown_0x10;
		int unknown_0x14;
		int index;
		char unknown_0x1C;
		char unknown_0x1D;
		char unknown_0x1E;
		char unknown_0x1F;
		void * conditions;
		long espFileOffset;
		Actor * speaker;
	};
	static_assert(sizeof(DialogueInfo) == 0x2C, "TES3::DialogueInfo failed size validation");
}

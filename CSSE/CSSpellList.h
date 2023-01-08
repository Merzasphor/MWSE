#pragma once

#include "CSDefines.h"
#include "NIIteratedList.h"

namespace se::cs {
	struct SpellList {
		int unknown_0x0;
		NI::IteratedList<Spell*> spells; // 0x4
	};
	static_assert(sizeof(SpellList) == 0x18, "SpellList failed size validation");
}

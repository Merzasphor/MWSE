#include "TES3LeveledList.h"

#define TES3_LeveledCreature_resolve 0x4CF870
#define TES3_LeveledItem_resolve 0x4D0BD0

namespace TES3 {
	Object * LeveledCreature::resolve() {
		return reinterpret_cast<Object*(__thiscall *)(LeveledCreature*)>(TES3_LeveledCreature_resolve)(this);
	}

	Object * LeveledItem::resolve() {
		return reinterpret_cast<Object*(__thiscall *)(LeveledItem*)>(TES3_LeveledItem_resolve)(this);
	}
}

#include "TES3LeveledList.h"

#define TES3_LeveledList_resolve 0x4D0BD0

namespace TES3 {
	Object * LeveledList::resolve() {
		return reinterpret_cast<Object*(__thiscall *)(LeveledList*)>(TES3_LeveledList_resolve)(this);
	}
}

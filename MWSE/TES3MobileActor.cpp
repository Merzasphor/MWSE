#include "TES3MobileActor.h"

#define TES3_MobileActor_getCell 0x521630

namespace TES3 {
	Cell* MobileActor::getCell() {
		return reinterpret_cast<Cell*(__thiscall *)(MobileActor*)>(TES3_MobileActor_getCell)(this);
	}
}

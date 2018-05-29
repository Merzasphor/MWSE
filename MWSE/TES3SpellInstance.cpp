#include "TES3SpellInstance.h"

#define TES3_SpellInstance_getSourceEffects 0x496FA0

namespace TES3 {
	Effect * SpellInstance::getSourceEffects() {
		return reinterpret_cast<Effect*(__thiscall *)(SpellInstance*)>(TES3_SpellInstance_getSourceEffects)(this);
	}
}

#include "TES3MagicSourceInstance.h"

#define TES3_MagicSourceInstance_getSourceEffects 0x496FA0

namespace TES3 {
	Effect * MagicSourceInstance::getSourceEffects() {
		return reinterpret_cast<Effect*(__thiscall *)(MagicSourceInstance*)>(TES3_MagicSourceInstance_getSourceEffects)(this);
	}
}

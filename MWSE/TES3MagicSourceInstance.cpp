#include "TES3MagicSourceInstance.h"

#define TES3_MagicSourceCombo_getSourceEffects 0x496FA0

namespace TES3 {
	Effect * MagicSourceCombo::getSourceEffects() {
		return reinterpret_cast<Effect*(__thiscall *)(MagicSourceCombo*)>(TES3_MagicSourceCombo_getSourceEffects)(this);
	}
}

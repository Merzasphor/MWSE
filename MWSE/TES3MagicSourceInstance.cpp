#include "TES3MagicSourceInstance.h"

namespace TES3 {
	const auto TES3_MagicSourceCombo_getSourceEffects = reinterpret_cast<Effect * (__thiscall*)(MagicSourceCombo *)>(0x496FA0);
	const auto TES3_MagicSourceInstance_getMagnitudeForIndex = reinterpret_cast<int (__thiscall*)(MagicSourceInstance *, int)>(0x518380);

	Effect * MagicSourceCombo::getSourceEffects() {
		return TES3_MagicSourceCombo_getSourceEffects(this);
	}

	int MagicSourceInstance::getMagnitude(int effectIndex) {
		return TES3_MagicSourceInstance_getMagnitudeForIndex(this, effectIndex);
	}
}

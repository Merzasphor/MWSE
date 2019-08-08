#include "TES3MagicSourceInstance.h"

namespace TES3 {
	const auto TES3_MagicSourceCombo_getSourceEffects = reinterpret_cast<Effect * (__thiscall*)(MagicSourceCombo *)>(0x496FA0);
	Effect * MagicSourceCombo::getSourceEffects() {
		return TES3_MagicSourceCombo_getSourceEffects(this);
	}

	const auto TES3_MagicSourceInstance_getMagnitudeForIndex = reinterpret_cast<int(__thiscall*)(MagicSourceInstance *, int)>(0x518380);
	int MagicSourceInstance::getMagnitude(int effectIndex) {
		return TES3_MagicSourceInstance_getMagnitudeForIndex(this, effectIndex);
	}

	const auto TES3_PlaySpellVFX = reinterpret_cast<void(__cdecl *)(MagicSourceInstance *, float, Vector3, Reference*, int, PhysicalObject*, int, int)>(0x515D60);
	void MagicSourceInstance::playSpellVFX(float duration, Vector3 position, Reference* attachedReference, int unknown0, PhysicalObject* effectVisual, int effectIndex, int unknown1) {
		TES3_PlaySpellVFX(this, duration, position, attachedReference, unknown0, effectVisual, effectIndex, unknown1);
	}
}

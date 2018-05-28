#include "TES3Spell.h"

#include "TES3Util.h"

#define TES3_Spell_calculateCastChance 0x4AA950

namespace TES3 {
	float Spell::calculateCastChance(Reference* caster, bool checkMagicka, int* weakestSchoolId) {
		MobileActor* mobileCaster = mwse::tes3::getAttachedMobileActor(caster);
		if (mobileCaster == NULL) {
			return 0.0f;
		}

		return calculateCastChance(mobileCaster, checkMagicka, weakestSchoolId);
	}

	float Spell::calculateCastChance(MobileActor* caster, bool checkMagicka, int* weakestSchoolId) {
		return reinterpret_cast<float(__thiscall *)(Spell*, MobileActor*, bool, int*)>(TES3_Spell_calculateCastChance)(this, caster, checkMagicka, weakestSchoolId);
	}
}

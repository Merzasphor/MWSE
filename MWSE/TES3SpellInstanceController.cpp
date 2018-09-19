#include "TES3SpellInstanceController.h"

namespace TES3 {
	const auto TES3_SpellInstanceController_removeSpellsByEffect = reinterpret_cast<MagicSourceInstance* (__thiscall*)(SpellInstanceController*, Reference*, int, int)>(0x455880);
	const auto TES3_SpellInstanceController_clearSpellEffect = reinterpret_cast<MagicSourceInstance* (__thiscall*)(SpellInstanceController*, Reference *, int, int, bool)>(0x4556C0);
	const auto TES3_SpellInstanceController_getInstanceFromSerial = reinterpret_cast<MagicSourceInstance* (__thiscall*)(SpellInstanceController*, unsigned int)>(0x4553B0);

	void SpellInstanceController::removeSpellsByEffect(Reference * reference, int effectId, int percentChance) {
		TES3_SpellInstanceController_removeSpellsByEffect(this, reference, effectId, percentChance);
	}

	void SpellInstanceController::clearSpellEffect(Reference * reference, int castType, int percentChance, bool removeSpell) {
		TES3_SpellInstanceController_clearSpellEffect(this, reference, castType, percentChance, removeSpell);
	}

	MagicSourceInstance * SpellInstanceController::getInstanceFromSerial(unsigned int serial) {
		return TES3_SpellInstanceController_getInstanceFromSerial(this, serial);
	}
}

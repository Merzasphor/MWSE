#include "TES3SpellInstanceController.h"

namespace TES3 {

	const auto TES3_SpellInstanceController_activateSpell = reinterpret_cast<unsigned int (__thiscall*)(SpellInstanceController*, Reference *, void *, MagicSourceCombo*)>(0x454A60);
	unsigned int SpellInstanceController::activateSpell(Reference * reference, void * sourceItem, MagicSourceCombo* source) {
		return TES3_SpellInstanceController_activateSpell(this, reference, sourceItem, source);
	}

	const auto TES3_SpellInstanceController_removeSpellsByEffect = reinterpret_cast<MagicSourceInstance* (__thiscall*)(SpellInstanceController*, Reference*, int, int)>(0x455880);
	void SpellInstanceController::removeSpellsByEffect(Reference * reference, int effectId, int percentChance) {
		TES3_SpellInstanceController_removeSpellsByEffect(this, reference, effectId, percentChance);
	}

	const auto TES3_SpellInstanceController_clearSpellEffect = reinterpret_cast<MagicSourceInstance* (__thiscall*)(SpellInstanceController*, Reference *, int, int, bool)>(0x4556C0);
	void SpellInstanceController::clearSpellEffect(Reference * reference, int castType, int percentChance, bool removeSpell) {
		TES3_SpellInstanceController_clearSpellEffect(this, reference, castType, percentChance, removeSpell);
	}

	const auto TES3_SpellInstanceController_getInstanceFromSerial = reinterpret_cast<MagicSourceInstance* (__thiscall*)(SpellInstanceController*, unsigned int)>(0x4553B0);
	MagicSourceInstance * SpellInstanceController::getInstanceFromSerial(unsigned int serial) {
		return TES3_SpellInstanceController_getInstanceFromSerial(this, serial);
	}
}

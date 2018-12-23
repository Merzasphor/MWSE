#pragma once

#include "TES3Defines.h"

namespace TES3 {
	struct SpellInstanceController {
		int unknown_0x0;
		int unknown_0x4;
		int unknown_0x8;
		int unknown_0xC;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		int unknown_0x1C;
		int unknown_0x20;
		int unknown_0x24;
		int unknown_0x28;
		int unknown_0x2C;
		int unknown_0x30;
		int unknown_0x34;

		//
		// Other related this-call functions.
		//

		unsigned int activateSpell(Reference * reference, void * sourceItem, MagicSourceCombo* source);
		void removeSpellsByEffect(Reference * reference, int effectId, int percentChance);
		void clearSpellEffect(Reference * reference, int castType, int percentChance, bool removeSpell);
		MagicSourceInstance * getInstanceFromSerial(unsigned int serial);

	};
	static_assert(sizeof(SpellInstanceController) == 0x38, "TES3::SpellInstanceController failed size validation");
}

#pragma once

#include "TES3Defines.h"

namespace TES3 {
	struct CombatSession {
		float combatDistance; // 0x0
		int unknown_0x4; // 0x4
		long ammoDamage; // 0x8
		MobileActor * parentActor; // 0xC
		EquipmentStack * selectedWeapon; // 0x10
		int unknown_0x14;
		EquipmentStack * selectedShield; // 0x18
		int unknown_0x1C;
		Spell * nextSpell; // 0x20
		void * unknown_0x24;
		int nextAction; // 0x28
		int unknown_0x2C;
		int unknown_0x30;
		int unknown_0x34;
		void * dequeSpells; // 0x38
		long dequeSpellsCount; // 0x3C
		int unknown_0x40;
		int unknown_0x44;
		char unknown_0x48;
		char unknown_0x49;
		char unknown_0x4A;
		char unknown_0x4B;

		//
		// Other related this-call functions.
		//

		void determineNextAction();

	};
	static_assert(sizeof(CombatSession) == 0x4C, "TES3::CombatSession failed size validation");
}

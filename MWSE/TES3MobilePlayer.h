#pragma once

#include "TES3Object.h"
#include "TES3GlobalVariable.h"
#include "TES3MobileNPC.h"

namespace TES3 {
	struct MobilePlayer : MobileNPC {
		int levelupPerAttributeCount[8]; // 0x56C
		int levelupPerSpecialization[3]; // 0x58C
		void * bounty; // 0x598
		Apparatus * apparatus0; // 0x59C
		Apparatus * apparatus1; // 0x5A0
		Apparatus * apparatus2; // 0x5A4
		Apparatus * apparatus3; // 0x5A8
		GlobalVariable * clawMultiplier; // 0x5AC
		signed char controlsDisabled; // 0x5B0
		signed char jumpingDisabled; // 0x5B1
		signed char mouselookDisabled; // 0x5B2
		signed char viewSwitchDisabled; // 0x5B3
		signed char vanityDisabled; // 0x5B4
		signed char attackDisabled; // 0x5B5
		signed char magicDisabled; // 0x5B6
		signed char alwaysRun; // 0x5B7
		signed char autoRun; // 0x5B8
		signed char sleeping; // 0x5B9
		char unknown_0x5BA; // 0x5BA // Resting related?
		char unknown_0x5BB; // 0x5BB
		char unknown_0x5BC; // 0x5BC
		signed char weaponReady; // 0x5BD
		signed char castReady; // 0x5BE
		char unknown_0x5BF;
		signed char playerInJail; // 0x5C0
		signed char playerIsTravelling; // 0x5C1
		char unknown_0x5C2; // Undefined.
		char unknown_0x5C3; // Undefined.
		int telekinesis; // 0x5C4
		float visionBonus; // 0x5C8
		int unknown_0x5CC;
		int unknown_0x5D0;
		int unknown_0x5D4;
		int unknown_0x5D8;
		int unknown_0x5DC;
		int unknown_0x5E0;
		int unknown_0x5E4; // Casting? Float?
		int levelUpProgress; // 0x5E8
		int restHoursRemaining; // 0x5EC
		int lastUsedAmmoCount; // 0x5F0
		float skillProgress[27]; // 0x5F4
		Reference * firstPersonReference; // 0x660
		NPC * firstPerson; // 0x664
		char unknown_0x668; // Bounty related.
		char unknown_0x669;
		char unknown_0x66A; // Undefined.
		char unknown_0x66B; // Undefined.
		int unknown_0x66C;
		void * birthsign; // 0x670
		void * dialogueList; // 0x674
		void * markLocation; // 0x678
		Vector3 field_67C;
		float inactivityTime; // 0x684
		int humanStatsBackup; // 0x688
		GlobalVariable * knownWerewolf; // 0x690

		//
		// Other related this-call functions.
		//

		void exerciseSkill(int skillId, float progress);
		void levelSkill(int skillId);

	};
	static_assert(sizeof(MobilePlayer) == 0x694, "TES3::MobilePlayer failed size validation");
}

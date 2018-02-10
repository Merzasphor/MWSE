#pragma once

#include "ObjectTypes.h"

namespace TES3 {
	struct Region_vTable {

	};

	struct Region {
		Region_vTable * vTable; // 0x00
		ObjectType::ObjectType objectType; // 0x04
		int baseFlags; // 0x08
		int unknown_0x0C;
		char ID[32]; // 0x10
		char name[32]; // 0x30
		unsigned char weatherChanceClear; // 0x50
		unsigned char weatherChanceCloudy; // 0x51
		unsigned char weatherChanceFoggy; // 0x52
		unsigned char weatherChanceOvercast; // 0x53
		unsigned char weatherChanceRain; // 0x54
		unsigned char weatherChanceThunder; // 0x55
		unsigned char weatherChanceAsh; // 0x56
		unsigned char weatherChanceBlight; // 0x57
		unsigned char weatherChanceSnow; // 0x58
		unsigned char weatherChanceBlizzard; // 0x59
		unsigned char unknown_0x5A;
		unsigned char unknown_0x5B;
		BaseObject * sleepCreature; // 0x5C
		int unknown_0x60[5]; // Unknown2 in Master?
		int unknown_0x74;
	};
	static_assert(sizeof(Region) == 0x78, "TES3::Region failed size validation");
}

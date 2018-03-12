#pragma once

#include "TES3Object.h"
#include "TES3Item.h"

namespace TES3 {
	namespace WeaponType {
		enum WeaponType {
			ShortBlade1H = 0x0,
			LongBlade1H = 0x1,
			LongBlade2H = 0x2,
			Blunt1H = 0x3,
			Blunt2close = 0x4,
			Blunt2wide = 0x5,
			Spear2H = 0x6,
			Axe1H = 0x7,
			Axe2H = 0x8,
			Bow = 0x9,
			Crossbow = 0xA,
			Thrown = 0xB,
			Arrow = 0xC,
			Bolt = 0xD
		};
	}

	struct Weapon : Item {
		float weight;
		int value;
		char weaponType;
		short maxCondition;
		float speed;
		float reach;
		short enchantCapacity;
		unsigned char chopMin;
		unsigned char chopMax;
		unsigned char slashMin;
		unsigned char slashMax;
		unsigned char thrustMin;
		unsigned char thrustMax;
		int materialFlags;
		Enchantment * enchantment;
	};
}

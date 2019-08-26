#pragma once

#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3Item.h"

namespace TES3 {
	namespace WeaponType {
		typedef unsigned char value_type;

		enum WeaponType : value_type {
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
		Iterator<TES3::BaseObject> stolenList; // 0x30
		char * name; // 0x44
		Script * script; // 0x48
		char * model; // 0x4C
		char * icon; // 0x50
		float weight; // 0x54
		int value; // 0x58
		WeaponType::value_type weaponType; // 0x5C
		unsigned short maxCondition; // 0x5E
		float speed; // 0x60
		float reach; // 0x64
		unsigned short enchantCapacity; // 0x68
		unsigned char chopMin; // 0x6A
		unsigned char chopMax; // 0x6B
		unsigned char slashMin; // 0x6C
		unsigned char slashMax; // 0x6D
		unsigned char thrustMin; // 0x6E
		unsigned char thrustMax; // 0x6F
		mwse::bitset32 materialFlags; // 0x70
		Enchantment * enchantment; // 0x74

		//
		// Custom functions.
		//

		bool isOneHanded();
		bool isTwoHanded();
		bool isMelee();
		bool isRanged();
		bool isAmmo();
		bool hasDurability();
	};
	static_assert(sizeof(Weapon) == 0x78, "TES3::Weapon failed size validation");
}

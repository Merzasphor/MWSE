#pragma once

#include "ObjectTypes.h"

#include "TES3Enchantment.h"

namespace TES3 {
	enum WeaponType {
		WeaponTypeShortBladeOneHand,
		WeaponTypeLongBladeOneHand,
		WeaponTypeLongBladeTwoClose,
		WeaponTypeBluntOneHand,
		WeaponTypeBluntTwoClose,
		WeaponTypeBluntTwoWide,
		WeaponTypeSpearTwoWide,
		WeaponTypeAxeOneHand,
		WeaponTypeAxeTwoHand,
		WeaponTypeMarksmanBow,
		WeaponTypeMarksmanCrossbow,
		WeaponTypeMarksmanThrown,
		WeaponTypeArrow,
		WeaponTypeBolt
	};

	struct Weapon_vTable {

	};

	struct Weapon {
		Weapon_vTable * vTable;
		ObjectType::ObjectType objectType;
		int baseFlags; // 0x08
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		BaseObject * previousRecord; // 0x1C
		BaseObject * nextRecord; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		mwString objectID; // 0x2C
		void * unknownFunctionPtr; // 0x30
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		mwString name; // 0x44
		int unknown_0x48;
		mwString model; // 0x4C
		mwString texture; // 0x50
		mwFloat weight; // 0x54
		mwLong value; // 0x58
		mwShort weaponType; // 0x5C
		mwShort maxCondition; // 0x5E
		mwFloat speed; // 0x60
		mwFloat reach; // 0x64
		mwShort enchantPoints; // 0x68
		char chopMin; // 0x6A
		char chopMax; // 0x6B
		char slashMin; // 0x6C
		char slashMax; // 0x6D
		char trustMin; // 0x6E
		char trustMax; // 0x6F
		mwLong flags; // 0x70
		Enchantment * enchantment; // 0x74
	};
	static_assert(sizeof(Weapon) == 0x78, "TES3::Weapon failed size validation");

	struct Ammo_vTable {

	};

	struct Ammo {
		Ammo_vTable * vTable;
		ObjectType::ObjectType objectType;
		int baseFlags; // 0x08
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		BaseObject * previousRecord; // 0x1C
		BaseObject * nextRecord; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		mwString objectID; // 0x2C
		void * unknownFunctionPtr; // 0x30
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		mwString name; // 0x44
		int unknown_0x48;
		mwString model; // 0x4C
		mwString texture; // 0x50
		mwFloat weight; // 0x54
		mwLong value; // 0x58
		long unknown_0x5C;
		long unknown_0x60;
		long unknown_0x64;
		long unknown_0x68;
		long unknown_0x6C;
		long unknown_0x70;
		Enchantment * enchantment; // 0x74
	};
	static_assert(sizeof(Weapon) == 0x78, "TES3::Weapon failed size validation");

	
}

#pragma once

#include "ObjectTypes.h"

#include "TES3Enchantment.h"

namespace TES3 {
	enum ArmorSlots {
		ArmorSlotHelmet,
		ArmorSlotCuirass,
		ArmorSlotLeftPauldron,
		ArmorSlotRightPauldron,
		ArmorSlotGreaves,
		ArmorSlotBoots,
		ArmorSlotLeftGauntlet,
		ArmorSlotRightGauntlet,
		ArmorSlotShield,
		ArmorSlotLeftBracer,
		ArmorSlotRightBracer
	};

	struct Armor_vTable {

	};

	struct Armor {
		Armor_vTable * vTable;
		ObjectType::ObjectType objectType;
		int baseFlags; // 0x08
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		BaseObject * previousRecord; // 0x1C
		BaseObject * nextObject; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		mwString objectID; // 0x2C
		void * unknownFunctionPtr; // 0x30
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		mwString name; // 0x44
		mwString model; // 0x48
		int unknown_0x4C;
		mwString texture; // 0x50
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C;
		int unknown_0x60[4];
		int unknown_0x70[4];
		int unknown_0x80[4];
		int unknown_0x90[3];
		mwShort maxCondition; // 0x9C
		mwShort unknown_0x9E;
		int unknown_0xA0;
		int unknown_0xA4;
		mwLong slot; // 0xA8
		mwFloat weight; // 0xAC
		mwLong value; // 0xB0
		int unknown_0xB4[3]; // 0xB4
		Enchantment * enchantment; // 0xC0
	};
}
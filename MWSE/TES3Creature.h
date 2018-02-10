#pragma once

#include "ObjectTypes.h"

#include "TES3Collections.h"

namespace TES3 {
	struct Creature_vTable {

	};

	struct Creature {
		Creature_vTable * vTable;
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
		mwLong unknown_0x30;
		mwLong unknown_0x34;
		mwLong unknown_0x38;
		mwLong unknown_0x3C;
		Iterator<InventoryNode> * inventory; // 0x40
		mwLong unknown_0x44;
		mwLong unknown_0x48;
		mwLong unknown_0x4C;
		mwLong unknown_0x50;
		mwLong unknown_0x54;
		mwLong unknown_0x58;
		mwLong unknown_0x5C;
		mwLong unknown_0x60;
		mwLong unknown_0x64;
		mwLong unknown_0x68;
		mwLong unknown_0x6C;
		mwString name; // 0x0070
		mwLong unknown_0x74;
		mwLong unknown_0x78;
		mwLong unknown_0x7C;
		mwLong unknown_0x80;
		mwLong unknown_0x84;
		mwLong unknown_0x88;
		mwLong unknown_0x8C;
		mwLong unknown_0x90;
		mwLong unknown_0x94;
		mwLong unknown_0x98;
		mwLong unknown_0x9C;
		mwLong unknown_0xA0;
		mwLong unknown_0xA4;
		mwLong unknown_0xA8;
		mwLong unknown_0xAC;
		mwLong unknown_0xB0;
		mwLong unknown_0xB4;
		mwLong unknown_0xB8;
		mwLong unknown_0xBC;
		mwLong unknown_0xC0;
		mwLong unknown_0xC4;
		mwLong unknown_0xC8;
		mwLong unknown_0xCC;
		mwLong unknown_0xD0;
		mwLong unknown_0xD4;
		mwShort baseGold; // 0xD8 -- Base barter gold.
		mwShort unknown_0xDA;
		mwLong unknown_0xDC;
		mwLong unknown_0xE0;
		mwLong unknown_0xE4;
	};
	static_assert(sizeof(Creature) == 0xE8, "TES3::Creature failed size validation");

	struct CreatureInstance_vTable {

	};

	struct CreatureInstance {
		CreatureInstance_vTable * vTable;
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
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		Iterator<BaseObject*> inventory; // 0x58
		int unknown_0x54;
		Iterator<BaseObject*> equipment; // 0x58
		Creature * baseCreature; // 0x6C
	};
	static_assert(sizeof(CreatureInstance) == 0x70, "TES3::CreatureInstance failed size validation"); // Unverified.
}

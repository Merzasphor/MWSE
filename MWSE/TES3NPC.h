#pragma once

#include "ObjectTypes.h"

#include "TES3Class.h"
#include "TES3Collections.h"
#include "TES3Race.h"
#include "TES3Spell.h"

namespace TES3 {
	struct NPC_vTable {

	};

	struct NPC {
		NPC_vTable * vTable; // 0x00
		ObjectType::ObjectType objectType; // 0x04
		int baseFlags; // 0x08
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		BaseObject * previousObject; // 0x1C
		BaseObject * nextObject; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		mwString objectID; // 0x2C
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		int unknown_0x48;
		int unknown_0x4C;
		int unknown_0x50;
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C;
		int unknown_0x60;
		int unknown_0x64;
		int unknown_0x68;
		int unknown_0x6C;
		mwString name; // 0x70
		int unknown_0x74;
		int unknown_0x78;
		mwShort level; // 0x7C
		mwShort unknown_0x7E;
		int unknown_0x80;
		int unknown_0x84;
		int unknown_0x88;
		int unknown_0x8C;
		int unknown_0x90;
		int unknown_0x94;
		int unknown_0x98;
		int unknown_0x9C;
		int unknown_0xA0;
		int unknown_0xA4;
		int unknown_0xA8;
		mwShort baseGold; // 0xAC
		mwShort unknown_0xAE;
		Race * race; // 0xB0
		Class * classRecord; // 0xB4
		int unknown_0xB8; // BODY (head)
		int unknown_0xBC; // BODY (hair)
		int unknown_0xC0;
		int unknown_0xC4;
		Iterator<Spell> spells; // 0xCC
		int unknown_0xDC;
		int unknown_0xE0;
		int unknown_0xE4;
		mwLong servicesMask; // 0xE8
		int unknown_0xEC;
	};
	static_assert(sizeof(NPC) == 0xF0, "TES3::NPC failed size validation");

	struct NPCInstance_vTable {

	};

	struct NPCInstance {
	TES3::NPCInstance_vTable * vTable; // 0x00
		ObjectType::ObjectType objectType; // 0x04
		int baseFlags; // 0x08
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		BaseObject * previousObject; // 0x1C
		BaseObject * nextObject; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		mwString objectID; // 0x2C
		int unknown_0x30;
		unsigned long flags; // 0x34
		int unknown_0x38;
		int unknown_0x3C;
		Iterator<InventoryNode*> inventory; // 0x40
		int unknown_0x54;
		Iterator<BaseObject*> equipment; // 0x58
		NPC * baseNPC; // 0x6C
	};
}

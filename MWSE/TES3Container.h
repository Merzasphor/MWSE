#pragma once

#include "ObjectTypes.h"

#include "TES3Collections.h"

namespace TES3 {
	struct Container_vTable {

	};

	struct Container {
		Container_vTable * vTable;
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
		mwLong inventoryFlags; // 0x3C
		Iterator<InventoryNode> inventory; // 0x40
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C;
		int unknown_0x60;
		int unknown_0x64;
		int unknown_0x68;
		mwString name; // 0x6C
		mwString model; // 0x70
		int unknown_0x74;
		mwFloat weight; // 0x78
	};
	static_assert(sizeof(Container) == 0x7C, "TES3::Container failed size validation");
}

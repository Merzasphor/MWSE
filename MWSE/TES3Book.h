#pragma once

#include "ObjectTypes.h"

#include "TES3Enchantment.h"
#include "TES3Script.h"

namespace TES3 {
	struct Book_vTable {

	};

	struct Book {
		Book_vTable * vTable;
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
		int unknown_0x30; // vtable of embedded object?
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		mwString name; // 0x44
		Script * script; // 0x48
		mwString model; // 0x4C
		mwString texture; // 0x50
		mwFloat weight; // 0x54
		mwLong value; // 0x58
		mwLong scroll; // 0x5C
		mwLong teachesSkill; // 0x60 // -1 = None
		mwLong enchantCapacity; // 0x64
		Enchantment * enchantment; // 0x68
		int unknown_0x6C;
	};
	static_assert(sizeof(Book) == 0x70, "TES3::Book failed size validation");
}

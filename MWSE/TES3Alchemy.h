#pragma once

#include "ObjectTypes.h"

#include "TES3Effect.h"
#include "TES3Script.h"

namespace TES3 {
	struct Alchemy_vTable {

	};

	struct Alchemy {
		Alchemy_vTable * vTable;
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
		int unknown_0x40;
		mwString name; // 0x44
		Script * script; // 0x48
		mwString model; // 0x4C
		mwString icon; // 0x50
		mwFloat weight; // 0x54
		mwLong value; // 0x58
		Effect effects[8]; // 0x5C
		mwLong flags; // 0x011C // 1 = AUTOCALC
	};
	static_assert(sizeof(Alchemy) == 0x120, "TES3::Alchemy failed size validation");
}

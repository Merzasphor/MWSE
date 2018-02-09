#pragma once

#include "ObjectTypes.h"

namespace TES3 {
	struct Misc_vTable {

	};

	struct Misc {
		Misc_vTable * vTable; // 0x00
		ObjectType::ObjectType objectType; // 0x04
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
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		int unknown_0x48;
		mwString model; // 0x4C
		mwString texture; // 0x50
		mwFloat weight; // 0x54
		mwLong value; // 0x58
		int unknown_0x5C;
	};
	static_assert(sizeof(Misc) == 0x60, "TES3::Misc failed size validation");
}
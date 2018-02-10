#pragma once

#include "ObjectTypes.h"

#include "TES3Sound.h"

namespace TES3 {
	struct Static_vTable {

	};

	struct Static {
		Static_vTable * vTable;
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
		mwString model; // 0x30
	};
	static_assert(sizeof(Static) == 0x34, "TES3::Static failed size validation");
}

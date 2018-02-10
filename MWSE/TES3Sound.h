#pragma once

#include "ObjectTypes.h"

namespace TES3 {
	struct Sound_vTable {

	};

	struct Sound {
		Sound_vTable * vTable;
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
	};
	//static_assert(sizeof(Sound) == 0x80, "TES3::Sound failed size validation");
}

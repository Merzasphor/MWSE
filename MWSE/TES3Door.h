#pragma once

#include "ObjectTypes.h"

#include "TES3Sound.h"

namespace TES3 {
	struct Door_vTable {

	};

	struct Door {
		Door_vTable * vTable;
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
		int unknown_0x30;
		char name[32]; // 0x34
		char model[32]; // 0x54
		int unknown_0x74;
		Sound * openSound;
		Sound * closeSound;
	};
	static_assert(sizeof(Door) == 0x80, "TES3::Door failed size validation");
}

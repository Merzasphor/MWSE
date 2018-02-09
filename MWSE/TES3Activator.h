#pragma once

#include "ObjectTypes.h"
#include "TES3Script.h"

/*
	Activator object structure.

	vTable @747FC4
*/

namespace TES3 {
	struct Activator_vTable {

	};

	struct Activator {
		Activator_vTable * vTable;
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
		mwString model; // 0x34
		mwString name; // 0x38
		Script * script;
	};
	static_assert(sizeof(Activator) == 0x40, "TES3::Activator failed size validation");
}

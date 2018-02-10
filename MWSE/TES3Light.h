#pragma once

#include "ObjectTypes.h"

namespace TES3 {
	struct Light_vTable {

	};

	struct Light {
		Light_vTable * vTable; // 0x00
		ObjectType::ObjectType objectType; // 0x04
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
		int unknown_0x44;
		mwString name; // 0x48
		int unknown_0x4C;
		mwString model; // 0x50
		mwString icon; // 0x54
		mwFloat weight; // 0x58
		mwLong value; // 0x5C
		int unknown_0x60;
		int unknown_0x64;
		int unknown_0x68;
		int unknown_0x6C;
		int unknown_0x70;
	};
	static_assert(sizeof(Light) == 0x74, "TES3::Light failed size validation");
}
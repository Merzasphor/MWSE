#pragma once

#include "ObjectTypes.h"

namespace TES3 {
	struct Lockpick_vTable {

	};

	struct Lockpick {
		Lockpick_vTable * vTable;
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
		char name[32]; // 0x44
		int unknown_0x64;
		char modal[32]; // 0x68
		char texture[32]; // 0x88
		mwFloat weight; // 0xA8
		mwLong value; // 0xAC
		mwFloat quality; // 0xB0
		mwShort maxCondition; // 0xB4
		mwShort unknown_0xB6;
	};
	static_assert(sizeof(Lockpick) == 0xB8, "TES3::Lockpick failed size validation");
}
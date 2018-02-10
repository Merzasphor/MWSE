#pragma once

#include "ObjectTypes.h"

#include "TES3Enchantment.h"

namespace TES3 {
	struct Clothing_vTable {

	};

	struct Clothing {
		Clothing_vTable * vTable;
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
		void * unknownFunctionPtr; // 0x30
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		char * nameStringPtr; // 0x44
		int unknown_0x48;	//char * scriptIDStringPtr;
		char * nifStringPtr; // 0x4C
		char * tgaStringPtr; // 0x50
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C[19];
		mwLong slot; // 0xA4
		mwFloat weight; // 0xA8
		mwShort value; // 0xB0
		mwShort unknown_0xB2;
		Enchantment * enchantment; // 0xB4
	};
	static_assert(sizeof(Clothing) == 0xB8, "TES3::Clothing failed size validation");
}
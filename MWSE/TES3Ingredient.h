#pragma once

#include "ObjectTypes.h"

#include "TES3Effect.h"

namespace TES3 {
	struct Ingredient_vTable {

	};

	struct Ingredient {
		Ingredient_vTable * vTable;
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
		char model[32]; // 0x64
		char texture[32]; // 0x84
		int unknown_0xA4;
		int unknown_0xA8;
		int unknown_0xAC;
		mwLong effects[4]; // 0xB0
		mwLong effectSkillIds[4]; // 0xC0
		mwLong effectAttributeIds[4]; // 0xD0
	};
	static_assert(sizeof(Ingredient) == 0xE0, "TES3::Ingredient failed size validation");
}

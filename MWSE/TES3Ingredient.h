#pragma once

#include "TES3Object.h"
#include "TES3Item.h"

namespace TES3 {
	struct Ingredient : PhysicalObject {
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
		long effects[4]; // 0xB0
		long effectSkillIds[4]; // 0xC0
		long effectAttributeIds[4]; // 0xD0
	};
	static_assert(sizeof(Ingredient) == 0xE0, "TES3::Ingredient failed size validation");
}

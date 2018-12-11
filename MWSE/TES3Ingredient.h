#pragma once

#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3Item.h"

namespace TES3 {
	struct Ingredient : Item {
		Iterator<TES3::BaseObject> stolenList; // 0x30
		char name[32]; // 0x44
		char model[32]; // 0x64
		Script * script; // 0x84
		char texture[32]; // 0x88
		float weight; // 0xA8
		int value; // 0xAC
		long effects[4]; // 0xB0
		long effectSkillIds[4]; // 0xC0
		long effectAttributeIds[4]; // 0xD0
	};
	static_assert(sizeof(Ingredient) == 0xE0, "TES3::Ingredient failed size validation");
}

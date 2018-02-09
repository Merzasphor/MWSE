#pragma once

#include "ObjectTypes.h"

namespace TES3 {
	enum Specialization {
		SpecializationCombat,
		SpecializationMagic,
		SpecializationStealth
	};

	struct Class_vTable {

	};

	struct Class {
		Class_vTable * vTable; // 0x00
		ObjectType::ObjectType objectType; // 0x04
		int baseFlags; // 0x08
		int unknown_0x0C;
		char id[32]; // 0x10
		char name[32]; // 0x30
		mwLong attributes[2]; // 0x34
		mwLong specialization; // 0x3C
		mwLong skills[10]; // 0x40 // Even indices [0,2,4,6,8] are minor skills and odd indices [1,3,5,7,9] are major skills.
						   // The nth major skill index corresponds to the nth major skill in the CS, from the top down.
		mwLong playable; // 0x84 Is this class available to PC? 0 = no, 1 = yes
		mwLong services; // 0x88
		int unknown_0x8C;
		int unknown_0x90;
	};
	static_assert(sizeof(Class) == 0x94, "TES3::Class failed size validation");
}

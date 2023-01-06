#pragma once

#include "CSObject.h"
#include "CSEffect.h"

namespace se::cs {
	struct Spell : Object {
		char* objectID; // 0x28
		char* name; // 0x2C
		unsigned char castType; // 0x2E
		unsigned short magickaCost; // 0x32
		Effect effects[8]; // 0x34
		unsigned int spellFlags; // 0xF4
		int useCount; // 0xF8
	};
	static_assert(sizeof(Spell) == 0xFC, "Spell failed size validation");
}


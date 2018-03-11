#pragma once

#include "TES3Object.h"
#include "TES3Item.h"

namespace TES3 {
	struct Book : Item {
		float weight; // 0x54
		long value; // 0x58
		int bookType;
		int skillToRaise;
		int unknown_0x64;
		Enchantment * enchantment;
		int unknown_0x6C;
	};
	static_assert(sizeof(Book) == 0x70, "TES3::Book failed size validation");
}

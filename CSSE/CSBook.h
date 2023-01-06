#pragma once

#include "CSPhysicalObject.h"

namespace se::cs {
	struct Book : PhysicalObject {
		struct BookData {
			float weight; // 0x0
			int value; // 0x4
			bool isScroll; // 0x8
			int skillId; // 0xC
			int enchantPoints; // 0x10
		};
		const char* name; // 0x48
		Script* script; // 0x4C
		const char* model; // 0x50
		const char* icon; // 0x54
		BookData bookData; // 0x58
		Object* enchantment; // 0x6C
		char* text; // 0x70
	};
	static_assert(sizeof(Book) == 0x74, "Book failed size validation");
}

#pragma once

#include "ObjectTypes.h"

namespace TES3 {
	struct GlobalVariable
	{
		void * vTable; // 0x00
		ObjectType::ObjectType objectType; // 0x04
		mwLong size; // 0x08
		int unknown_0x0C;
		char name[32]; // 0x10
		char type; // 0x30 // Morrowind converts this to uppercase, can be 'l', 's', 'f' (long, short, float).
		char unknown_0x31[3]; // 3 bytes of padding.
		mwFloat data;
	};
	static_assert(sizeof(GlobalVariable) == 0x38, "TES3::GlobalVariable failed size validation");
}

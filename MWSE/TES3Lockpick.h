#pragma once

#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3Item.h"

namespace TES3 {
	struct Lockpick : Item {
		Iterator<TES3::BaseObject> stolenList; // 0x30
		char name[32]; // 0x44
		Script * script; // 0x64
		char modal[32]; // 0x68
		char icon[32]; // 0x88
		float weight; // 0xA8
		long value; // 0xAC
		float quality; // 0xB0
		short maxCondition; // 0xB4
		short unknown_0xB6;
	};
	static_assert(sizeof(Lockpick) == 0xB8, "TES3::Lockpick failed size validation");
}

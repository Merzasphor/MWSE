#pragma once

#include "TES3Defines.h"

#include "TES3Object.h"

namespace TES3 {
	struct ItemData {
		int count; // 0x0
		BaseObject * owner; // 0x4
		union {
			long rank;
			GlobalVariable * variable;
		} requirement; // 0x8
		int condition; // 0xC
		union {
			float charge;
			Actor* soul;
		} enchantData;  // 0x10
		Script * script; // 0x14
		ScriptVariables * scriptData; // 0x18
	};
	static_assert(sizeof(ItemData) == 0x1C, "TES3::ItemData failed size validation");

	// Dummy structure we mostly use for Lua casting.
	struct Item : PhysicalObject {};
	static_assert(sizeof(Item) == 0x30, "TES3::Item failed size validation");
}

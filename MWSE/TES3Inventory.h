#pragma once

#include "sol_forward.hpp"

#include "TES3Defines.h"

#include "TES3Collections.h"

namespace TES3 {
	struct ItemStack {
		int count; // 0x0
		Object * object; // 0x4
		TArray<ItemData> * variables; // 0x8

		//
		// Lua interface functions.
		//

		sol::object getObjectLua();

	};
	static_assert(sizeof(ItemStack) == 0xC, "TES3::ItemStack failed size validation");

	struct EquipmentStack {
		Object * object; // 0x0
		ItemData * variables; // 0x4

		//
		// Lua interface functions.
		//

		sol::object getObjectLua();
	};
	static_assert(sizeof(EquipmentStack) == 0x8, "TES3::EquipmentStack failed size validation");

	struct Inventory {
		unsigned int flags; // 0x0
		Iterator<ItemStack> iterator; // 0x4
		int unknown_0x18;

		//
		// Other related this-call functions.
		//

		void resolveLeveledLists(MobileActor*);

	};
	static_assert(sizeof(Inventory) == 0x1C, "TES3::Inventory failed size validation");
}

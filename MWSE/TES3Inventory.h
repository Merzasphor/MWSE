#pragma once

#include "sol_forward.hpp"

#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3Vectors.h"

#include "Bitset.h"

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
		// Other related helper functions.
		//

		int getAdjustedValue();

		//
		// Lua interface functions.
		//

		sol::object getObjectLua();
	};
	static_assert(sizeof(EquipmentStack) == 0x8, "TES3::EquipmentStack failed size validation");

	struct Inventory {
		mwse::bitset32 flags; // 0x0
		Iterator<ItemStack> iterator; // 0x4
		int unknown_0x18;

		//
		// Other related this-call functions.
		//

		ItemStack* findItemStack(Object* item);

		int addItem(MobileActor * mobile, Item * item, int count, bool overwriteCount, ItemData ** itemDataRef);
		int addItemWithoutData(MobileActor * mobile, Item * item, int count, bool something);
		ItemData* addItemByReference(MobileActor * mobile, Reference * reference, int * out_count);
		void removeItemWithData(MobileActor * mobile, Item * item, ItemData * itemData, int count, bool deleteStackData);
		void dropItem(MobileActor* mobileActor, Item * item, ItemData * itemData, int count, Vector3 position, Vector3 orientation, bool unknown = false);

		void resolveLeveledLists(MobileActor*);

		//
		// Custom functions.
		//

		bool containsItem(Item * item, ItemData * data = nullptr);

		float calculateContainedWeight();

		int getSoulGemCount();

	};
	static_assert(sizeof(Inventory) == 0x1C, "TES3::Inventory failed size validation");
}

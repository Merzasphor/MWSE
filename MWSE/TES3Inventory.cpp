#include "TES3Inventory.h"

namespace TES3 {
	const auto TES3_Inventory_findItemStack = reinterpret_cast<ItemStack* (__thiscall*)(Inventory*, Object*)>(0x49A6C0);
	const auto TES3_Inventory_resolveLeveledLists = reinterpret_cast<void (__thiscall*)(Inventory*, MobileActor*)>(0x49A190);

	const auto TES3_CalculateBarterItemValue = reinterpret_cast<int(__cdecl*)(const TES3::EquipmentStack*)>(0x5A46E0);

	int EquipmentStack::getAdjustedValue() {
		return TES3_CalculateBarterItemValue(this);
	}

	ItemStack* Inventory::findItemStack(Object* item) {
		return TES3_Inventory_findItemStack(this, item);
	}

	void Inventory::resolveLeveledLists(MobileActor* actor) {
		TES3_Inventory_resolveLeveledLists(this, actor);
	}
}

#include "TES3Inventory.h"

#include "TES3Util.h"

namespace TES3 {
	const auto TES3_Inventory_findItemStack = reinterpret_cast<ItemStack* (__thiscall*)(Inventory*, Object*)>(0x49A6C0);
	const auto TES3_Inventory_resolveLeveledLists = reinterpret_cast<void (__thiscall*)(Inventory*, MobileActor*)>(0x49A190);
	const auto TES3_Inventory_DropItem = reinterpret_cast<void(__thiscall*)(Inventory*, MobileActor*, Item *, ItemData *, int, Vector3, Vector3, bool)>(0x49B090);

	const auto TES3_CalculateBarterItemValue = reinterpret_cast<int(__cdecl*)(const TES3::EquipmentStack*)>(0x5A46E0);

	int EquipmentStack::getAdjustedValue() {
		return TES3_CalculateBarterItemValue(this);
	}

	void Inventory::dropItem(MobileActor* mobileActor, Item * item, ItemData * itemData, int count, Vector3 position, Vector3 orientation, bool unknown) {
		TES3_Inventory_DropItem(this, mobileActor, item, itemData, count, position, orientation, unknown);
	}

	ItemStack* Inventory::findItemStack(Object* item) {
		return TES3_Inventory_findItemStack(this, item);
	}

	void Inventory::resolveLeveledLists(MobileActor* actor) {
		TES3_Inventory_resolveLeveledLists(this, actor);
	}

	int Inventory::getSoulGemCount() {
		int count = 0;

		for (auto i = iterator.head; i; i = i->next) {
			if (mwse::tes3::isSoulGem(i->data->object)) {
				count++;
			}
		}

		return count;
	}
}

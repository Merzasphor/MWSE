#include "TES3Inventory.h"

#include "TES3Util.h"

#include "TES3Item.h"

namespace TES3 {
	//
	// EquipmentStack
	//

	const auto TES3_EquipmentStack_CalculateBarterItemValue = reinterpret_cast<int(__cdecl*)(const TES3::EquipmentStack*)>(0x5A46E0);
	int EquipmentStack::getAdjustedValue() {
		return TES3_EquipmentStack_CalculateBarterItemValue(this);
	}

	//
	// Inventory
	//

	const auto TES3_Inventory_findItemStack = reinterpret_cast<ItemStack* (__thiscall*)(Inventory*, Object*)>(0x49A6C0);
	ItemStack* Inventory::findItemStack(Object* item) {
		return TES3_Inventory_findItemStack(this, item);
	}

	const auto TES3_Inventory_AddItem = reinterpret_cast<int(__thiscall*)(Inventory*, MobileActor *, Item *, int, bool, ItemData **)>(0x498530);
	int Inventory::addItem(MobileActor * mobile, Item * item, int count, bool something, ItemData ** itemDataRef) {
		return TES3_Inventory_AddItem(this, mobile, item, count, something, itemDataRef);
	}

	const auto TES3_Inventory_RemoveItemWithData = reinterpret_cast<void(__thiscall*)(Inventory*, MobileActor*, Item *, ItemData *, int, bool)>(0x499550);
	void Inventory::removeItemWithData(MobileActor * mobile, Item * item, ItemData * itemData, int count, bool deleteStackData) {
		TES3_Inventory_RemoveItemWithData(this, mobile, item, itemData, count, deleteStackData);
	}

	const auto TES3_Inventory_DropItem = reinterpret_cast<void(__thiscall*)(Inventory*, MobileActor*, Item *, ItemData *, int, Vector3, Vector3, bool)>(0x49B090);
	void Inventory::dropItem(MobileActor* mobileActor, Item * item, ItemData * itemData, int count, Vector3 position, Vector3 orientation, bool unknown) {
		TES3_Inventory_DropItem(this, mobileActor, item, itemData, count, position, orientation, unknown);
	}

	const auto TES3_Inventory_resolveLeveledLists = reinterpret_cast<void(__thiscall*)(Inventory*, MobileActor*)>(0x49A190);
	void Inventory::resolveLeveledLists(MobileActor* actor) {
		TES3_Inventory_resolveLeveledLists(this, actor);
	}

	bool Inventory::containsItem(Item * item, ItemData * data) {
		ItemStack * stack = findItemStack(item);
		if (stack == nullptr) {
			return false;
		}

		if (data) {
			return stack->variables->contains(data);
		}

		return false;
	}

	float Inventory::calculateContainedWeight() {
		float weight = 0.0f;
		for (auto i = iterator.head; i; i = i->next) {
			weight += i->data->object->getWeight() * std::abs(i->data->count);
		}
		return weight;
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

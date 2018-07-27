#include "TES3Actor.h"

#include "LuaManager.h"

namespace TES3 {
	const auto TES3_Actor_equipItem = reinterpret_cast<Object* (__thiscall*)(Actor*, Object*, ItemData*, EquipmentStack**, MobileActor*)>(0x4958B0);
	const auto TES3_Actor_unequipItem = reinterpret_cast<EquipmentStack* (__thiscall*)(Actor*, Object*, bool, MobileActor*, bool, ItemData*)>(0x496710);
	const auto TES3_Actor_dropItem = reinterpret_cast<Reference* (__thiscall*)(Actor*, Object*, ItemData*, int, bool)>(0x52C460);
	const auto TES3_Actor_getEquippedArmorBySlot = reinterpret_cast<EquipmentStack* (__thiscall*)(Actor*, ArmorSlot::value_type)>(0x496E60);
	const auto TES3_Actor_getEquippedClothingBySlot = reinterpret_cast<EquipmentStack* (__thiscall*)(Actor*, ClothingSlot::value_type)>(0x496E00);

	int Actor::getBaseBarterGold() {
		return vTable.actor->getBaseBarterGold(this);
	}

	void Actor::setBaseBarterGold(int value) {
		vTable.actor->setBaseBarterGold(this, value);
	}

	bool Actor::getIsAttacked() {
		return vTable.actor->getIsAttacked(this);
	}

	unsigned int Actor::clone(Reference* reference) {
		return vTable.actor->clone(this, reference);
	}

	Object* Actor::equipItem(Object* item, ItemData* itemData, EquipmentStack** out_equipmentStack, MobileActor* mobileActor) {
		Object* result = TES3_Actor_equipItem(this, item, itemData, out_equipmentStack, mobileActor);

		// Trigger or queue our event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::EquippedEvent(this, mobileActor, item, itemData));

		return result;
	}

	EquipmentStack* Actor::unequipItem(Object* item, bool deleteStack, MobileActor* mobileActor, bool updateGUI, ItemData* itemData) {
		EquipmentStack* result = TES3_Actor_unequipItem(this, item, deleteStack, mobileActor, updateGUI, itemData);

		// Trigger or queue our event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::UnequippedEvent(this, mobileActor, item, itemData));

		return result;
	}

	Reference* Actor::dropItem(Object* item, ItemData* itemData = 0, int count = 1, bool matchAny = true) {
		return TES3_Actor_dropItem(this, item, itemData, count, matchAny);
	}

	EquipmentStack* Actor::getEquippedArmorBySlot(ArmorSlot::value_type slot) {
		return TES3_Actor_getEquippedArmorBySlot(this, slot);
	}

	EquipmentStack* Actor::getEquippedClothingBySlot(ClothingSlot::value_type slot) {
		return TES3_Actor_getEquippedClothingBySlot(this, slot);
	}

	bool Actor::getActorFlag(ActorFlag::Flag flag) {
		return (actorFlags & flag) != 0;
	}

	void Actor::setActorFlag(ActorFlag::Flag flag, bool set) {
		if (set) {
			actorFlags |= flag;
		}
		else {
			actorFlags &= ~flag;
		}
	}
}

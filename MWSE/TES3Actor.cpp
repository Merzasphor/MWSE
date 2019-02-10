#include "TES3Actor.h"
#include "TES3MobileActor.h"
#include "TES3MobilePlayer.h"

#include "LuaManager.h"

#include "LuaEquippedEvent.h"
#include "LuaUnequippedEvent.h"

namespace TES3 {
	const auto TES3_Actor_equipItem = reinterpret_cast<Object* (__thiscall*)(Actor*, Object*, ItemData*, EquipmentStack**, MobileActor*)>(0x4958B0);
	const auto TES3_Actor_unequipItem = reinterpret_cast<EquipmentStack* (__thiscall*)(Actor*, Object*, bool, MobileActor*, bool, ItemData*)>(0x496710);
	const auto TES3_Actor_dropItem = reinterpret_cast<Reference* (__thiscall*)(Actor*, Object*, ItemData*, int, bool)>(0x52C460);
	const auto TES3_Actor_getEquippedArmorBySlot = reinterpret_cast<EquipmentStack* (__thiscall*)(Actor*, ArmorSlot::value_type)>(0x496E60);
	const auto TES3_Actor_getEquippedClothingBySlot = reinterpret_cast<EquipmentStack* (__thiscall*)(Actor*, ClothingSlot::value_type)>(0x496E00);
	const auto TES3_Actor_getEquippedItem = reinterpret_cast<EquipmentStack* (__thiscall*)(Actor*, Object*)>(0x496DD0);

	Actor * Actor::getBaseActor() {
		return vTable.actor->getBaseActor(this);
	}

	int Actor::getBaseBarterGold() {
		return vTable.actor->getBaseBarterGold(this);
	}

	void Actor::setBaseBarterGold(int value) {
		vTable.actor->setBaseBarterGold(this, value);
	}

	bool Actor::getIsAttacked() {
		return vTable.actor->getIsAttacked(this);
	}

	void Actor::clone(Reference* reference) {
		vTable.actor->clone(this, reference);
	}

	void Actor::onCloseInventory(Actor* actor, Reference* reference, int unknown) {
		vTable.actor->onCloseInventory(actor, reference, unknown);
	}

	void Actor::setAIPackage(AIPackageConfig* packageConfig, Reference* reference) {
		vTable.actor->setAIPackage(this, packageConfig, reference);
	}

	Object* Actor::equipItem(Object* item, ItemData* itemData, EquipmentStack** out_equipmentStack, MobileActor* mobileActor) {
		Object* result = TES3_Actor_equipItem(this, item, itemData, out_equipmentStack, mobileActor);

		// Trigger or queue our event, if this actor has a mobile actor.
		if (mobileActor) {
			mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::EquippedEvent(this, mobileActor, item, itemData));
		}

		return result;
	}

	EquipmentStack* Actor::unequipItem(Object* item, bool deleteStack, MobileActor* mobileActor, bool updateGUI, ItemData* itemData) {
		EquipmentStack* result = TES3_Actor_unequipItem(this, item, deleteStack, mobileActor, updateGUI, itemData);

		// Trigger or queue our event if there's an attached mobile actor.
		if (mobileActor) {
			mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::UnequippedEvent(this, mobileActor, item, itemData));
		}

		return result;
	}

	const auto TES3_Actor_unequipAllItems = reinterpret_cast<void(__thiscall*)(Actor*, MobileActor*)>(0x496680);
	void Actor::unequipAllItems(MobileActor * mobileActor) {
		TES3_Actor_unequipAllItems(this, mobileActor);
	}

	Reference* Actor::dropItem(Object* item, ItemData* itemData = 0, int count = 1, bool matchAny = true) {
		return TES3_Actor_dropItem(this, item, itemData, count, matchAny);
	}

	void Actor::postUnequipUIRefresh(MobileActor* mobileActor) {
		// UI refresh code from the tail of TES3_Actor_unequipItem
		// Required to work around a crashing bug with unequipping lights
		const auto TES3_Reference_updateBodyParts = reinterpret_cast<void (__thiscall*)(Reference*)>(0x4E8B50);
		const auto TES3_ui_inventoryUpdateIcons = reinterpret_cast<void (__cdecl*)()>(0x5CC910);
		const auto TES3_ui_inventoryUpdateWindowTitle = reinterpret_cast<void (__cdecl*)()>(0x5CE080);
		const auto TES3_ui_updateCharacterImage = reinterpret_cast<void (__cdecl*)(bool)>(0x5CD2A0);
		const auto TES3_ui_updateMagicMenu = reinterpret_cast<void (__cdecl*)()>(0x5E2E80);

		if (mobileActor->actorType == MobileActorType::Player) {
			auto player = static_cast<MobilePlayer*>(mobileActor);

			if (player->actorFlags & MobileActorFlag::BodypartsChanged) {
				TES3_Reference_updateBodyParts(player->reference);
				TES3_Reference_updateBodyParts(player->firstPersonReference);
				player->actorFlags &= ~MobileActorFlag::BodypartsChanged;
			}

			TES3_ui_inventoryUpdateIcons();
			TES3_ui_inventoryUpdateWindowTitle();
			TES3_ui_updateCharacterImage(false);
			TES3_ui_updateMagicMenu();
		}
	}

	EquipmentStack* Actor::getEquippedItem(Object* item) {
		return TES3_Actor_getEquippedItem(this, item);
	}

	EquipmentStack* Actor::getEquippedArmorBySlot(ArmorSlot::value_type slot) {
		return TES3_Actor_getEquippedArmorBySlot(this, slot);
	}

	EquipmentStack* Actor::getEquippedClothingBySlot(ClothingSlot::value_type slot) {
		return TES3_Actor_getEquippedClothingBySlot(this, slot);
	}

	bool Actor::getActorFlag(unsigned int flag) {
		return (actorFlags & flag) != 0;
	}

	void Actor::setActorFlag(unsigned int flag, bool set) {
		if (set) {
			actorFlags |= flag;
		}
		else {
			actorFlags &= ~flag;
		}
	}

	bool Actor::isBaseActor() {
		return (actorFlags & TES3::ActorFlag::IsBase);
	}

	bool Actor::isClone() {
		return !(actorFlags & TES3::ActorFlag::IsBase);
	}
}

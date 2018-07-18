#include "TES3Actor.h"

#include "LuaManager.h"

#define TES3_Actor_equipItem 0x4958B0
#define TES3_Actor_unequipItem 0x496710
#define TES3_Actor_dropItem 0x52C460

namespace TES3 {
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

	int Actor::equipItem(TES3::BaseObject* item, TES3::ItemData* itemData, TES3::EquipmentStack** out_equipmentStack, TES3::MobileActor* mobileActor) {
		int result = reinterpret_cast<int(__thiscall *)(TES3::Actor*, TES3::BaseObject*, TES3::ItemData*, TES3::EquipmentStack**, TES3::MobileActor*)>(TES3_Actor_equipItem)(this, item, itemData, out_equipmentStack, mobileActor);

		// Trigger or queue our event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::EquippedEvent(this, mobileActor, item, itemData));

		return result;
	}

	TES3::EquipmentStack * Actor::unequipItem(TES3::Item* item, bool deleteStack, TES3::MobileActor* mobileActor, bool updateGUI, TES3::ItemData* itemData) {
		TES3::EquipmentStack * result = reinterpret_cast<TES3::EquipmentStack *(__thiscall *)(TES3::Actor*, TES3::Item*, bool, TES3::MobileActor*, bool, TES3::ItemData*)>(TES3_Actor_unequipItem)(this, item, deleteStack, mobileActor, updateGUI, itemData);

		// Trigger or queue our event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::UnequippedEvent(this, mobileActor, item, itemData));

		return result;
	}

	Reference* Actor::dropItem(BaseObject* item, ItemData* itemData = 0, int count = 1, bool matchAny = true) {
		return reinterpret_cast<Reference*(__thiscall *)(Actor*, BaseObject*, ItemData*, int, bool)>(TES3_Actor_dropItem)(this, item, itemData, count, matchAny);
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
}

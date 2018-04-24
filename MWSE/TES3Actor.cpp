#include "TES3Actor.h"

#define TES3_Actor_equipItem 0x4958B0
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

	void Actor::equipItem(TES3::BaseObject* item, TES3::ItemData* itemData, TES3::EquipmentStack** out_equipmentStack, TES3::MobileActor* mobileActor) {
		reinterpret_cast<void(__thiscall *)(TES3::Actor*, TES3::BaseObject*, TES3::ItemData*, TES3::EquipmentStack**, TES3::MobileActor*)>(TES3_Actor_equipItem)(this, item, itemData, out_equipmentStack, mobileActor);
	}

	Reference* Actor::dropItem(BaseObject* item, ItemData* itemData = 0, int count = 1, bool matchAny = true) {
		return reinterpret_cast<Reference*(__thiscall *)(Actor*, BaseObject*, ItemData*, int, bool)>(TES3_Actor_dropItem)(this, item, itemData, count, matchAny);
	}
}

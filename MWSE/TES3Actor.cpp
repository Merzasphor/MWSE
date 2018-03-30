#include "TES3Actor.h"

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

	Reference* Actor::dropItem(BaseObject* item, ItemData* itemData = 0, int count = 1, bool matchAny = true) {
		return reinterpret_cast<Reference*(__thiscall *)(Actor*, BaseObject*, ItemData*, int, bool)>(TES3_Actor_dropItem)(this, item, itemData, count, matchAny);
	}
}

#include "TES3Actor.h"

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
}

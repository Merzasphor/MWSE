#include "TES3Item.h"

#include "TES3ItemData.h"

namespace TES3 {
	ItemData * Item::createItemData() {
		return ItemData::createForObject(this);
	}

	bool Item::promptsEquipmentReevaluation() const {
		switch (objectType) {
		case ObjectType::Armor:
		case ObjectType::Clothing:
		case ObjectType::Weapon:
			return true;
		}
		return false;
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::Item)

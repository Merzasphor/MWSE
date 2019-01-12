#include "TES3Item.h"

#include "TES3ItemData.h"

namespace TES3 {
	ItemData * Item::createItemData() {
		return ItemData::createForObject(this);
	}
}

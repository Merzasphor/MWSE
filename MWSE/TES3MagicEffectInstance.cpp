#include "TES3MagicEffectInstance.h"

#include "TES3Item.h"
#include "TES3Inventory.h"

namespace TES3 {
	float MagicEffectInstance::getEffectiveMagnitude() const {
		return magnitude * (1.0f - resistedPercent / 100.0f);
	}

	bool MagicEffectInstance::isBoundItem() const {
		if (createdData) {
			return createdData->object->objectType != ObjectType::Reference;
		}
		return false;
	}

	bool MagicEffectInstance::isSummon() const {
		if (createdData) {
			return createdData->object->objectType == ObjectType::Reference;
		}
		return false;
	}
}

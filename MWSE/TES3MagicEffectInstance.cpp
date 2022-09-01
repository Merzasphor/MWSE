#include "TES3MagicEffectInstance.h"

#include "TES3Item.h"
#include "TES3Inventory.h"

namespace TES3 {
	float MagicEffectInstance::getEffectiveMagnitude() const {
		return magnitude * (1.0f - resistedPercent / 100.0f);
	}

	EquipmentStack* MagicEffectInstance::getCreatedStack() const {
		// This function tries to get the equipment / summon data.
		// The MagicEffectInstance does not contain the effect id, so there is no way to discriminate if
		// this is a vampirism effect and therefore if createdData is a vampire head id without more context.
		// Instead, check if the value looks like a small non-pointer head id.
		if (reinterpret_cast<uintptr_t>(createdData.equipmentOrSummon) < 0x10000u) {
			return nullptr;
		}
		return createdData.equipmentOrSummon;
	}

	bool MagicEffectInstance::isBoundItem() const {
		auto stack = getCreatedStack();
		if (stack) {
			return stack->object->objectType != ObjectType::Reference;
		}
		return false;
	}

	bool MagicEffectInstance::isSummon() const {
		auto stack = getCreatedStack();
		if (stack) {
			return stack->object->objectType == ObjectType::Reference;
		}
		return false;
	}
}

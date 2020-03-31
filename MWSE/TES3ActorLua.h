#pragma once

#include "TES3ObjectLua.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForActor(T& usertypeDefinition) {
			setUserdataForPhysicalObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["actorFlags"] = sol::readonly_property(&TES3::Actor::actorFlags);
			usertypeDefinition["cloneCount"] = sol::readonly_property(&TES3::Actor::cloneCount);
			usertypeDefinition["equipment"] = sol::readonly_property(&TES3::Actor::equipment);
			usertypeDefinition["inventory"] = sol::readonly_property(&TES3::Actor::inventory);

			// Functions exposed as properties.
			usertypeDefinition["barterGold"] = sol::property(&TES3::Actor::getBaseBarterGold, &TES3::Actor::setBaseBarterGold);
			usertypeDefinition["blood"] = sol::property(&TES3::Actor::getBloodType, &TES3::Actor::setBloodType);

			// Basic function binding.
			usertypeDefinition["tradesItemType"] = &TES3::Actor::tradesItemType;

			// Function exposing.
			usertypeDefinition["onInventoryClose"] = [](TES3::Actor& self, sol::optional<TES3::Reference*> reference, sol::optional<int> unknown) {
				self.onCloseInventory(reference.value_or(nullptr), unknown.value_or(0));
			};
		}
	}
}

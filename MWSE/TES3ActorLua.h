#pragma once

#include "TES3ObjectLua.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForActor(sol::simple_usertype<T>& usertypeDefinition) {
			setUserdataForPhysicalObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("actorFlags", sol::readonly_property(&TES3::Actor::actorFlags));
			usertypeDefinition.set("cloneCount", sol::readonly_property(&TES3::Actor::cloneCount));
			usertypeDefinition.set("equipment", sol::readonly_property(&TES3::Actor::equipment));
			usertypeDefinition.set("inventory", sol::readonly_property(&TES3::Actor::inventory));

			// Functions exposed as properties.
			usertypeDefinition.set("barterGold", sol::property(&TES3::Actor::getBaseBarterGold, &TES3::Actor::setBaseBarterGold));

			// Function exposing.
			usertypeDefinition.set("onInventoryClose", [](TES3::Actor& self, sol::optional<TES3::Reference*> reference, sol::optional<int> unknown) {
				self.onCloseInventory(&self, reference.value_or(nullptr), unknown.value_or(0));
			});
		}
	}
}

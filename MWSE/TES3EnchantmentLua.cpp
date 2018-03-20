#include "TES3EnchantmentLua.h"

#include "LuaManager.h"

#include "TES3Enchantment.h"
#include "TES3Script.h"

namespace TES3 {
	sol::object Enchantment::getEffectsTable() {
		// Get our lua state.
		sol::state& state = mwse::lua::LuaManager::getInstance().getState();

		// Build a table of TES3::Effect* objects to pass back.
		sol::table result = state.create_table();
		for (int i = 0; i < 8; i++) {
			// Insert a pointer to the effect. Convert index to be 1-based.
			result[i + 1] = sol::make_object(state, &effects[i]);
		}
		return result;
	}
}

namespace mwse {
	namespace lua {
		void bindTES3Enchantment() {
			LuaManager::getInstance().getState().new_usertype<TES3::Enchantment>("TES3Enchantment",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Enchantment::objectType,

				"id", sol::readonly_property(&TES3::Enchantment::getObjectID),

				"flags", sol::readonly(&TES3::Enchantment::flags),
				"autoCalc", sol::property(&TES3::Enchantment::getAutoCalc, &TES3::Enchantment::setAutoCalc),
				"type", &TES3::Enchantment::castType,
				"cost", &TES3::Enchantment::chargeCost,
				"charge", &TES3::Enchantment::maxCharge,

				"effects", sol::readonly_property(&TES3::Enchantment::getEffectsTable)

				);
		}
	}
}

#include "TES3EnchantmentLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Enchantment() {
			LuaManager::getInstance().getState().new_usertype<TES3::Enchantment>("TES3Enchantment",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::base_classes, sol::bases<TES3::BaseObject>(),

				sol::meta_function::to_string, &TES3::Enchantment::getObjectID,

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

				"effects", sol::readonly_property([](TES3::Enchantment& self) { return std::ref(self.effects); })

				);
		}
	}
}

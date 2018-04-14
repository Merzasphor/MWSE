#include "TES3WeaponLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Weapon() {
			LuaManager::getInstance().getState().new_usertype<TES3::Weapon>("TES3Weapon",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Weapon::objectType,

				"id", sol::readonly_property(&TES3::Weapon::getObjectID),
				"name", sol::property(&TES3::Weapon::getName, &TES3::Weapon::setName),

				"icon", sol::readonly_property(&TES3::Weapon::getIconPath),
				"model", sol::readonly_property(&TES3::Weapon::getModelPath),

				"type", sol::readonly_property(&TES3::Weapon::getType),
				"typeName", sol::readonly_property(&TES3::Weapon::getTypeName),

				"flags", &TES3::Weapon::materialFlags,
				"weight", sol::readonly_property(&TES3::Weapon::getWeight),
				"value", sol::readonly_property(&TES3::Weapon::getValue),
				"health", sol::readonly_property(&TES3::Weapon::getDurability),
				"speed", &TES3::Weapon::speed,
				"reach", &TES3::Weapon::reach,

				"chopMin", &TES3::Weapon::chopMin,
				"chopMax", &TES3::Weapon::chopMax,
				"slashMin", &TES3::Weapon::slashMin,
				"slashMax", &TES3::Weapon::slashMax,
				"thrustMin", &TES3::Weapon::thrustMin,
				"thrustMax", &TES3::Weapon::thrustMax,

				"enchantCapacity", &TES3::Weapon::enchantCapacity,
				"enchantment", sol::property(&TES3::Weapon::getEnchantment, &TES3::Weapon::setEnchantment),

				"script", sol::readonly_property(&TES3::Weapon::getScript)

				);
		}
	}
}

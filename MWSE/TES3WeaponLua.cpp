#include "TES3WeaponLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Enchantment.h"
#include "TES3Script.h"
#include "TES3Weapon.h"

namespace mwse {
	namespace lua {
		void bindTES3Weapon() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Weapon>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
			setUserdataForPhysicalObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("chopMax", &TES3::Weapon::chopMax);
			usertypeDefinition.set("chopMin", &TES3::Weapon::chopMin);
			usertypeDefinition.set("enchantCapacity", &TES3::Weapon::enchantCapacity);
			usertypeDefinition.set("enchantment", sol::property(&TES3::Weapon::getEnchantment, &TES3::Weapon::setEnchantment));
			usertypeDefinition.set("flags", &TES3::Weapon::materialFlags);
			usertypeDefinition.set("maxCondition", sol::property(&TES3::Weapon::getDurability, &TES3::Weapon::setDurability));
			usertypeDefinition.set("icon", sol::readonly_property(&TES3::Weapon::getIconPath));
			usertypeDefinition.set("mesh", sol::readonly_property(&TES3::Weapon::getModelPath));
			usertypeDefinition.set("name", sol::property(&TES3::Weapon::getName, &TES3::Weapon::setName));
			usertypeDefinition.set("reach", &TES3::Weapon::reach);
			usertypeDefinition.set("slashMax", &TES3::Weapon::slashMax);
			usertypeDefinition.set("slashMin", &TES3::Weapon::slashMin);
			usertypeDefinition.set("speed", &TES3::Weapon::speed);
			usertypeDefinition.set("thrustMax", &TES3::Weapon::thrustMax);
			usertypeDefinition.set("thrustMin", &TES3::Weapon::thrustMin);
			usertypeDefinition.set("type", sol::readonly_property(&TES3::Weapon::getType));
			usertypeDefinition.set("value", &TES3::Weapon::value);
			usertypeDefinition.set("weight", &TES3::Weapon::weight);

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("script", sol::readonly_property(&TES3::Weapon::getScript));

			// Functions exposed as properties.
			usertypeDefinition.set("hasDurability", sol::readonly_property(&TES3::Weapon::hasDurability));
			usertypeDefinition.set("isOneHanded", sol::readonly_property(&TES3::Weapon::isOneHanded));
			usertypeDefinition.set("isTwoHanded", sol::readonly_property(&TES3::Weapon::isTwoHanded));
			usertypeDefinition.set("isMelee", sol::readonly_property(&TES3::Weapon::isMelee));
			usertypeDefinition.set("isRanged", sol::readonly_property(&TES3::Weapon::isRanged));
			usertypeDefinition.set("isAmmo", sol::readonly_property(&TES3::Weapon::isAmmo));
			usertypeDefinition.set("typeName", sol::readonly_property(&TES3::Weapon::getTypeName));

			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition.set("health", sol::readonly_property(&TES3::Weapon::getDurability));
			usertypeDefinition.set("model", sol::readonly_property(&TES3::Weapon::getModelPath));

			// Finish up our usertype.
			state.set_usertype("tes3weapon", usertypeDefinition);
		}
	}
}

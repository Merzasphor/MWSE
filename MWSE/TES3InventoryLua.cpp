#include "TES3Actor.h"

#include "LuaManager.h"
#include "LuaUtil.h"

namespace TES3 {
	sol::object ItemStack::getObjectLua() {
		return mwse::lua::makeLuaObject(object);
	}

	sol::object EquipmentStack::getObjectLua() {
		return mwse::lua::makeLuaObject(object);
	}
}

namespace mwse {
	namespace lua {
		void bindTES3Inventory() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::ItemStack>("TES3ItemStack",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"count", sol::readonly_property(&TES3::ItemStack::count),
				"object", sol::readonly_property(&TES3::ItemStack::getObjectLua),
				"variables", sol::readonly_property(&TES3::ItemStack::variables)

				);

			state.new_usertype<TES3::EquipmentStack>("TES3EquipmentStack",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"object", sol::readonly_property(&TES3::EquipmentStack::getObjectLua),
				"variables", sol::readonly_property(&TES3::EquipmentStack::variables)

				);
		}
	}
}

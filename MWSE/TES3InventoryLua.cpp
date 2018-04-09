#include "TES3InventoryLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Inventory.h"
#include "TES3Script.h"
#include "TES3ScriptLua.h"

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

			state.new_usertype<TES3::ItemVariables>("TES3ItemVariables",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"count", sol::readonly_property(&TES3::ItemVariables::count),
				"condition", sol::readonly_property(&TES3::ItemVariables::condition),
				"script", sol::readonly_property(&TES3::ItemVariables::script),

				"context", sol::readonly_property([](TES3::ItemVariables& self) { return std::shared_ptr<ScriptContext>(new ScriptContext(self.script, self.scriptData)); })

				);

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

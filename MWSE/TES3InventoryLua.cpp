#include "TES3InventoryLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Item.h"
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

			state.new_usertype<TES3::ItemData>("TES3ItemData",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"count", sol::readonly_property(&TES3::ItemData::count),
				"condition", &TES3::ItemData::condition,
				"charge", sol::property(
					[](TES3::ItemData& self) { return self.enchantData.charge; },
					[](TES3::ItemData& self, float value) { self.enchantData.charge = value; }
					),

				"script", sol::readonly_property(&TES3::ItemData::script),
				"context", sol::readonly_property([](TES3::ItemData& self) { return std::shared_ptr<ScriptContext>(new ScriptContext(self.script, self.scriptData)); })

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

			state.new_usertype<TES3::Inventory>("TES3Inventory",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"flags", sol::readonly_property(&TES3::Inventory::flags),
				"iterator", sol::readonly_property(&TES3::Inventory::iterator)

				);
		}
	}
}

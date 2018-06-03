#include "TES3MagicEffectInstanceLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Armor.h"
#include "TES3Light.h"
#include "TES3MagicEffectInstance.h"
#include "TES3Reference.h"
#include "TES3Weapon.h"

namespace mwse {
	namespace lua {
		void bindTES3MagicEffectInstance() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::MagicEffectInstance>("TES3MagicEffectInstance",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"target", sol::readonly_property([](TES3::MagicEffectInstance& self) { return makeLuaObject(self.target); }),
				"resistedPercent", &TES3::MagicEffectInstance::resistedPercent,
				"magnitude", &TES3::MagicEffectInstance::magnitude,
				"timeActive", &TES3::MagicEffectInstance::timeActive,
				"cumulativeMagnitude", &TES3::MagicEffectInstance::cumulativeMagnitude,
				"state", &TES3::MagicEffectInstance::state,
				"visual", &TES3::MagicEffectInstance::visual,
				"lastUsedWeapon", sol::readonly_property([](TES3::MagicEffectInstance& self) { return makeLuaObject(self.lastUsedWeapon); }),
				"lastUsedArmor", sol::readonly_property([](TES3::MagicEffectInstance& self) { return makeLuaObject(self.lastUsedArmor); }),
				"lastUsedShield", sol::readonly_property([](TES3::MagicEffectInstance& self) { return makeLuaObject(self.lastUsedShield); }),
				"lastUsedLight", sol::readonly_property([](TES3::MagicEffectInstance& self) { return makeLuaObject(self.lastUsedLight); }),
				"lastUsedEnchItem", sol::readonly_property([](TES3::MagicEffectInstance& self) { return makeLuaObject(self.lastUsedEnchItem); })

				//
				// Functions
				//



				);
		}
	}
}

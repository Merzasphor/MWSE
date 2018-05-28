#include "TES3SpellEffectInstanceLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"
#include "LuaUtil.h"

namespace mwse {
	namespace lua {
		void bindTES3SpellEffectInstance() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::SpellEffectInstance>("TES3SpellEffectInstance",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"target", sol::readonly_property([](TES3::SpellEffectInstance& self) { return makeLuaObject(self.spellTarget); }),
				"resistedPercent", &TES3::SpellEffectInstance::resistedPercent,
				"magnitude", &TES3::SpellEffectInstance::magnitude,
				"timeActive", &TES3::SpellEffectInstance::timeActive,
				"cumulativeMagnitude", &TES3::SpellEffectInstance::cumulativeMagnitude,
				"state", &TES3::SpellEffectInstance::state,
				"spellVisual", &TES3::SpellEffectInstance::spellVisual,
				"lastUsedWeapon", sol::readonly_property([](TES3::SpellEffectInstance& self) { return makeLuaObject(self.lastUsedWeapon); }),
				"lastUsedArmor", sol::readonly_property([](TES3::SpellEffectInstance& self) { return makeLuaObject(self.lastUsedArmor); }),
				"lastUsedShield", sol::readonly_property([](TES3::SpellEffectInstance& self) { return makeLuaObject(self.lastUsedShield); }),
				"lastUsedLight", sol::readonly_property([](TES3::SpellEffectInstance& self) { return makeLuaObject(self.lastUsedLight); }),
				"lastUsedEnchItem", sol::readonly_property([](TES3::SpellEffectInstance& self) { return makeLuaObject(self.lastUsedEnchItem); })

				//
				// Functions
				//



				);
		}
	}
}

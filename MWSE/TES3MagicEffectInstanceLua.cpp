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
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::MagicEffectInstance>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Basic property binding.
			usertypeDefinition.set("cumulativeMagnitude", &TES3::MagicEffectInstance::cumulativeMagnitude);
			usertypeDefinition.set("magnitude", &TES3::MagicEffectInstance::magnitude);
			usertypeDefinition.set("resistedPercent", &TES3::MagicEffectInstance::resistedPercent);
			usertypeDefinition.set("state", &TES3::MagicEffectInstance::state);
			usertypeDefinition.set("timeActive", &TES3::MagicEffectInstance::timeActive);
			usertypeDefinition.set("visual", &TES3::MagicEffectInstance::visual);

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("lastUsedArmor", sol::readonly_property([](TES3::MagicEffectInstance& self) { return makeLuaObject(self.lastUsedArmor); }));
			usertypeDefinition.set("lastUsedEnchItem", sol::readonly_property([](TES3::MagicEffectInstance& self) { return makeLuaObject(self.lastUsedEnchItem); }));
			usertypeDefinition.set("lastUsedLight", sol::readonly_property([](TES3::MagicEffectInstance& self) { return makeLuaObject(self.lastUsedLight); }));
			usertypeDefinition.set("lastUsedShield", sol::readonly_property([](TES3::MagicEffectInstance& self) { return makeLuaObject(self.lastUsedShield); }));
			usertypeDefinition.set("lastUsedWeapon", sol::readonly_property([](TES3::MagicEffectInstance& self) { return makeLuaObject(self.lastUsedWeapon); }));
			usertypeDefinition.set("target", sol::readonly_property([](TES3::MagicEffectInstance& self) { return makeLuaObject(self.target); }));

			// Finish up our usertype.
			state.set_usertype("tes3magicEffectInstance", usertypeDefinition);
		}
	}
}

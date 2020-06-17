#include "TES3MagicEffectInstanceLua.h"

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
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::MagicEffectInstance>("tes3magicEffectInstance");
			usertypeDefinition["new"] = sol::no_constructor;

			// Basic property binding.
			usertypeDefinition["cumulativeMagnitude"] = &TES3::MagicEffectInstance::cumulativeMagnitude;
			usertypeDefinition["magnitude"] = &TES3::MagicEffectInstance::magnitude;
			usertypeDefinition["resistedPercent"] = &TES3::MagicEffectInstance::resistedPercent;
			usertypeDefinition["state"] = &TES3::MagicEffectInstance::state;
			usertypeDefinition["timeActive"] = &TES3::MagicEffectInstance::timeActive;
			usertypeDefinition["visual"] = &TES3::MagicEffectInstance::visual;

			// Access to other objects that need to be packaged.
			usertypeDefinition["lastUsedArmor"] = sol::readonly_property([](TES3::MagicEffectInstance& self) { return self.lastUsedArmor; });
			usertypeDefinition["lastUsedEnchItem"] = sol::readonly_property([](TES3::MagicEffectInstance& self) { return self.lastUsedEnchItem; });
			usertypeDefinition["lastUsedLight"] = sol::readonly_property([](TES3::MagicEffectInstance& self) { return self.lastUsedLight; });
			usertypeDefinition["lastUsedShield"] = sol::readonly_property([](TES3::MagicEffectInstance& self) { return self.lastUsedShield; });
			usertypeDefinition["lastUsedWeapon"] = sol::readonly_property([](TES3::MagicEffectInstance& self) { return self.lastUsedWeapon; });
			usertypeDefinition["target"] = sol::readonly_property([](TES3::MagicEffectInstance& self) { return self.target; });
		}
	}
}

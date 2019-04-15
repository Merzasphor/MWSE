#include "TES3MobileProjectileLua.h"

#include "LuaManager.h"
#include "TES3MobileObjectLua.h"

#include "TES3MobileProjectile.h"
#include "TES3MobileActor.h"
#include "TES3Weapon.h"

namespace mwse {
	namespace lua {
		void bindTES3MobileProjectile() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::MobileProjectile>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::MobileObject>());
			setUserdataForMobileObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("disposition", &TES3::MobileProjectile::disposition);
			usertypeDefinition.set("expire", &TES3::MobileProjectile::flagExpire);

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("firingMobile", sol::readonly_property([](TES3::MobileProjectile& self) { return makeLuaObject(self.firingActor); }));
			usertypeDefinition.set("firingWeapon", sol::readonly_property([](TES3::MobileProjectile& self) { return makeLuaObject(self.firingWeapon); }));

			// Finish up our usertype.
			state.set_usertype("tes3mobileProjectile", usertypeDefinition);
		}
	}
}

#include "TES3MobileProjectileLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3MobileProjectile.h"
#include "TES3MobileActor.h"
#include "TES3Weapon.h"

namespace mwse {
	namespace lua {
		void bindTES3MobileProjectile() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto mobileProjectileUsertype = state.create_simple_usertype<TES3::MobileProjectile>();
			mobileProjectileUsertype.set("new", sol::no_constructor);

			// We inherit MobileObject.
			mobileProjectileUsertype.set(sol::base_classes, sol::bases<TES3::MobileObject>());

			// Basic property binding.
			mobileProjectileUsertype.set("disposition", &TES3::MobileProjectile::disposition);
			mobileProjectileUsertype.set("expire", &TES3::MobileProjectile::flagExpire);

			// Access to other objects that need to be packaged.
			mobileProjectileUsertype.set("firingMobile", sol::readonly_property([](TES3::MobileProjectile& self) { return makeLuaObject(self.firingActor); }));
			mobileProjectileUsertype.set("firingWeapon", sol::readonly_property([](TES3::MobileProjectile& self) { return makeLuaObject(self.firingWeapon); }));

			// Finish up our usertype.
			state.set_usertype("TES3MobileProjectile", mobileProjectileUsertype);
		}
	}
}

#include "TES3MobileProjectileLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3MobileProjectile.h"
#include "TES3Reference.h"
#include "TES3Weapon.h"

namespace mwse {
	namespace lua {
		void bindTES3MobileProjectile() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::MobileProjectile>("TES3MobileProjectile",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::MobileProjectile::objectType,

				"movementFlags", &TES3::MobileProjectile::movementFlags,
				"prevMovementFlags", &TES3::MobileProjectile::prevMovementFlags,
				"actorFlags", &TES3::MobileProjectile::actorFlags,
				"flagExpire", &TES3::MobileProjectile::flagExpire,

				"reference", sol::readonly_property(&TES3::MobileProjectile::reference),
				"firingMobile", sol::readonly_property([](TES3::MobileProjectile& self) { return mwse::lua::makeLuaObject(self.firingActor); }),
				"firingWeapon", sol::readonly_property(&TES3::MobileProjectile::firingWeapon),

				"cellX", sol::readonly_property(&TES3::MobileProjectile::cellX),
				"cellY", sol::readonly_property(&TES3::MobileProjectile::cellY),

				"height", &TES3::MobileProjectile::height,
				"boundSize", &TES3::MobileProjectile::boundSize,
				"velocity", &TES3::MobileProjectile::velocity,
				"impulseVelocity", &TES3::MobileProjectile::impulseVelocity,
				"position", &TES3::MobileProjectile::position

				);
		}
	}
}

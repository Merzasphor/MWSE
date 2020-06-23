#pragma once

#include "TES3MobileActor.h"
#include "TES3Weapon.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForTES3MobileProjectile(sol::usertype<T>& usertypeDefinition) {
			setUserdataForTES3MobileObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["expire"] = &TES3::MobileProjectile::flagExpire;
			usertypeDefinition["firingMobile"] = sol::readonly_property(&TES3::MobileProjectile::firingActor);
			usertypeDefinition["firingWeapon"] = sol::readonly_property(&TES3::MobileProjectile::firingWeapon);
		}

		void bindTES3MobileProjectile();
	}
}

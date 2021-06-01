#pragma once

#include "TES3MobileActor.h"
#include "TES3Weapon.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForTES3MobileProjectile(sol::usertype<T>& usertypeDefinition) {
			setUserdataForTES3MobileObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["animTime"] = &TES3::MobileProjectile::animTime;
			usertypeDefinition["attackSwing"] = &TES3::MobileProjectile::attackSwing;
			usertypeDefinition["damage"] = &TES3::MobileProjectile::damage;
			usertypeDefinition["expire"] = &TES3::MobileProjectile::flagExpire;
			usertypeDefinition["firingMobile"] = sol::readonly_property(&TES3::MobileProjectile::firingActor);
			usertypeDefinition["firingWeapon"] = sol::readonly_property(&TES3::MobileProjectile::firingWeapon);
			usertypeDefinition["initialSpeed"] = sol::readonly_property(&TES3::MobileProjectile::initialSpeed);
			usertypeDefinition["velocity"] = &TES3::MobileProjectile::velocity;
		}

		void bindTES3MobileProjectile();
	}
}

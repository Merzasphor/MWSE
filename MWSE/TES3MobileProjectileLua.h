#pragma once


namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForTES3MobileProjectile(sol::usertype<T>& usertypeDefinition) {
			setUserdataForTES3MobileObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["expire"] = &TES3::MobileProjectile::flagExpire;

			// Access to other objects that need to be packaged.
			usertypeDefinition["firingMobile"] = sol::readonly_property([](TES3::MobileProjectile& self) { return self.firingActor; });
			usertypeDefinition["firingWeapon"] = sol::readonly_property([](TES3::MobileProjectile& self) { return self.firingWeapon; });
		}

		void bindTES3MobileProjectile();
	}
}

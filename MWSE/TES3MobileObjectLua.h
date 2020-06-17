#pragma once

#include "LuaUtil.h"

#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForMobileObject(T& usertypeDefinition) {
			// Basic property binding.
			usertypeDefinition["objectType"] = sol::readonly_property(&TES3::MobileObject::objectType);
			usertypeDefinition["flags"] = sol::readonly_property(&TES3::MobileObject::actorFlags);
			usertypeDefinition["boundSize"] = sol::readonly_property(&TES3::MobileObject::boundSize);
			usertypeDefinition["cellX"] = sol::readonly_property(&TES3::MobileObject::cellX);
			usertypeDefinition["cellY"] = sol::readonly_property(&TES3::MobileObject::cellY);
			usertypeDefinition["height"] = sol::readonly_property(&TES3::MobileObject::height);
			usertypeDefinition["movementFlags"] = sol::readonly_property(&TES3::MobileObject::movementFlags);
			usertypeDefinition["prevMovementFlags"] = sol::readonly_property(&TES3::MobileObject::prevMovementFlags);

			// Vectors we want to handle differently, and allow table aliasing.
			usertypeDefinition["impulseVelocity"] = sol::property([](TES3::MobileObject& self) { return &self.impulseVelocity; }, &TES3::MobileObject::setImpulseVelocityFromLua);
			usertypeDefinition["position"] = sol::property([](TES3::MobileObject& self) { return &self.position; }, &TES3::MobileObject::setPositionFromLua);
			usertypeDefinition["velocity"] = sol::property([](TES3::MobileObject& self) { return &self.velocity; }, &TES3::MobileObject::setVelocityFromLua);

			// Access to other objects that need to be packaged.
			usertypeDefinition["reference"] = sol::readonly_property([](TES3::MobileObject& self) { return self.reference; });
		}
	}
}

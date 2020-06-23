#pragma once

#include "LuaUtil.h"

#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForTES3MobileObject(sol::usertype<T>& usertypeDefinition) {
			// Basic property binding.
			usertypeDefinition["objectType"] = sol::readonly_property(&TES3::MobileObject::objectType);
			usertypeDefinition["flags"] = sol::readonly_property(&TES3::MobileObject::actorFlags);
			usertypeDefinition["boundSize"] = sol::readonly_property(&TES3::MobileObject::boundSize);
			usertypeDefinition["cellX"] = sol::readonly_property(&TES3::MobileObject::cellX);
			usertypeDefinition["cellY"] = sol::readonly_property(&TES3::MobileObject::cellY);
			usertypeDefinition["height"] = sol::readonly_property(&TES3::MobileObject::height);
			usertypeDefinition["movementFlags"] = sol::readonly_property(&TES3::MobileObject::movementFlags);
			usertypeDefinition["prevMovementFlags"] = sol::readonly_property(&TES3::MobileObject::prevMovementFlags);
			usertypeDefinition["reference"] = sol::readonly_property(&TES3::MobileObject::reference);

			// Vectors we want to handle differently, and allow table aliasing.
			usertypeDefinition["impulseVelocity"] = sol::property(&TES3::MobileObject::impulseVelocity, &TES3::MobileObject::setImpulseVelocityFromLua);
			usertypeDefinition["position"] = sol::property(&TES3::MobileObject::position, &TES3::MobileObject::setPositionFromLua);
			usertypeDefinition["velocity"] = sol::property(&TES3::MobileObject::velocity, &TES3::MobileObject::setVelocityFromLua);
		}
	}
}

#pragma once

#include "LuaUtil.h"

#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForMobileObject(sol::simple_usertype<T>& usertypeDefinition) {
			// Basic property binding.
			usertypeDefinition.set("objectType", sol::readonly_property(&TES3::MobileObject::objectType));
			usertypeDefinition.set("flags", sol::readonly_property(&TES3::MobileObject::actorFlags));
			usertypeDefinition.set("boundSize", sol::readonly_property(&TES3::MobileObject::boundSize));
			usertypeDefinition.set("cellX", sol::readonly_property(&TES3::MobileObject::cellX));
			usertypeDefinition.set("cellY", sol::readonly_property(&TES3::MobileObject::cellY));
			usertypeDefinition.set("height", sol::readonly_property(&TES3::MobileObject::height));
			usertypeDefinition.set("movementFlags", sol::readonly_property(&TES3::MobileObject::movementFlags));
			usertypeDefinition.set("prevMovementFlags", sol::readonly_property(&TES3::MobileObject::prevMovementFlags));

			// Vectors we want to handle differently, and allow table aliasing.
			usertypeDefinition.set("impulseVelocity", sol::property([](TES3::MobileObject& self) { return &self.impulseVelocity; }, &TES3::MobileObject::setImpulseVelocityFromLua));
			usertypeDefinition.set("position", sol::property([](TES3::MobileObject& self) { return &self.position; }, &TES3::MobileObject::setPositionFromLua));
			usertypeDefinition.set("velocity", sol::property([](TES3::MobileObject& self) { return &self.velocity; }, &TES3::MobileObject::setVelocityFromLua));

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("reference", sol::readonly_property([](TES3::MobileObject& self) { return makeLuaObject(self.reference); }));
		}
	}
}

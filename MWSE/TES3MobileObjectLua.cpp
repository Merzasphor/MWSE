#include "TES3MobileObjectLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3MobileObject.h"
#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		void bindTES3MobileObject() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::MobileObject>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Basic property binding.
			usertypeDefinition.set("actorFlags", sol::readonly_property(&TES3::MobileObject::actorFlags));
			usertypeDefinition.set("boundSize", sol::readonly_property(&TES3::MobileObject::boundSize));
			usertypeDefinition.set("cellX", sol::readonly_property(&TES3::MobileObject::cellX));
			usertypeDefinition.set("cellY", sol::readonly_property(&TES3::MobileObject::cellY));
			usertypeDefinition.set("height", sol::readonly_property(&TES3::MobileObject::height));
			usertypeDefinition.set("movementFlags", sol::readonly_property(&TES3::MobileObject::movementFlags));
			usertypeDefinition.set("prevMovementFlags", sol::readonly_property(&TES3::MobileObject::prevMovementFlags));

			// Vectors we want to handle differently, and allow table aliasing.
			usertypeDefinition.set("impulseVelocity", sol::property(&TES3::MobileObject::impulseVelocity, &TES3::MobileObject::setImpulseVelocityFromLua));
			usertypeDefinition.set("position", sol::property(&TES3::MobileObject::position, &TES3::MobileObject::setPositionFromLua));
			usertypeDefinition.set("velocity", sol::property(&TES3::MobileObject::velocity, &TES3::MobileObject::setVelocityFromLua));

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("reference", sol::readonly_property([](TES3::MobileObject& self) { return makeLuaObject(self.reference); }));

			// Finish up our usertype.
			state.set_usertype("TES3MobileObject", usertypeDefinition);
		}
	}
}

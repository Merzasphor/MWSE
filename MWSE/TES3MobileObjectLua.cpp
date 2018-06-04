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
			auto mobileObjectUsertype = state.create_simple_usertype<TES3::MobileObject>();
			mobileObjectUsertype.set("new", sol::no_constructor);

			// Basic property binding.
			mobileObjectUsertype.set("movementFlags", sol::readonly_property(&TES3::MobileObject::movementFlags));
			mobileObjectUsertype.set("prevMovementFlags", sol::readonly_property(&TES3::MobileObject::prevMovementFlags));
			mobileObjectUsertype.set("actorFlags", sol::readonly_property(&TES3::MobileObject::actorFlags));
			mobileObjectUsertype.set("cellX", sol::readonly_property(&TES3::MobileObject::cellX));
			mobileObjectUsertype.set("cellY", sol::readonly_property(&TES3::MobileObject::cellY));
			mobileObjectUsertype.set("height", sol::readonly_property(&TES3::MobileObject::height));
			mobileObjectUsertype.set("boundSize", sol::readonly_property(&TES3::MobileObject::boundSize));
			mobileObjectUsertype.set("velocity", sol::readonly_property(&TES3::MobileObject::velocity));
			mobileObjectUsertype.set("impulseVelocity", sol::readonly_property(&TES3::MobileObject::impulseVelocity));
			mobileObjectUsertype.set("position", sol::readonly_property(&TES3::MobileObject::position));

			// Access to other objects that need to be packaged.
			mobileObjectUsertype.set("reference", sol::readonly_property([](TES3::MobileObject& self) { return makeLuaObject(self.reference); }));

			// Finish up our usertype.
			state.set_usertype("TES3MobileObject", mobileObjectUsertype);
		}
	}
}

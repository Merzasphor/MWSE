//#include "TES3CollisionLua.h"

#include "LuaManager.h"
#include "TES3MobileObjectLua.h"

#include "TES3MobileObject.h"

namespace mwse {
	namespace lua {
		void bindTES3Collision() {
			using Collision = TES3::MobileObject::Collision;
			static const double quantizer = 1.0 / 32767.0;

			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::MobileObject::Collision>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Basic property binding.
			usertypeDefinition.set("collisionType", sol::readonly_property(&Collision::collisionType));
			usertypeDefinition.set("objectPosAtCollision", sol::readonly_property(&Collision::objectPosAtCollision));
			usertypeDefinition.set("point", sol::readonly_property(&Collision::point));
			usertypeDefinition.set("time", sol::readonly_property(&Collision::fTime));
			usertypeDefinition.set("valid", sol::readonly_property(&Collision::valid));
			usertypeDefinition.set("velocity", sol::readonly_property(&Collision::velocity));

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("colliderRef", sol::readonly_property([](Collision& self) { return makeLuaObject(self.colliderRef); }));
			usertypeDefinition.set("colliderRoot", sol::readonly_property([](Collision& self) { return makeLuaNiPointer(self.colliderRoot); }));
			usertypeDefinition.set("normal", sol::readonly_property([](Collision& self) {
				return TES3::Vector3(self.quantizedNormal[0] * quantizer, self.quantizedNormal[1] * quantizer, self.quantizedNormal[2] * quantizer);
			}));

			// Finish up our usertype.
			state.set_usertype("tes3mobileObjectCollision", usertypeDefinition);
		}
	}
}

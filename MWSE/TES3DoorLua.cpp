#include "TES3DoorLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Door.h"
#include "TES3Script.h"
#include "TES3Sound.h"

namespace mwse {
	namespace lua {
		void bindTES3Door() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Door>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
			setUserdataForPhysicalObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("closeSound", &TES3::Door::closeSound);
			usertypeDefinition.set("openSound", &TES3::Door::openSound);

			// Functions exposed as properties.
			usertypeDefinition.set("mesh", sol::property(&TES3::Door::getModelPath, &TES3::Door::setModelPath));
			usertypeDefinition.set("name", sol::property(&TES3::Door::getName, &TES3::Door::setName));
			usertypeDefinition.set("script", sol::property(&TES3::Door::getScript));

			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition.set("model", sol::property(&TES3::Door::getModelPath, &TES3::Door::setModelPath));

			// Finish up our usertype.
			state.set_usertype("tes3door", usertypeDefinition);
		}
	}
}

#include "TES3ActivatorLua.h"

#include "LuaManager.h"

#include "TES3ObjectLua.h"

#include "TES3Activator.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Activator() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Activator>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
			setUserdataForPhysicalObject(usertypeDefinition);

			// Functions exposed as properties.
			usertypeDefinition.set("mesh", sol::property(&TES3::Activator::getModelPath, &TES3::Activator::setModelPath));
			usertypeDefinition.set("name", sol::property(&TES3::Activator::getName, &TES3::Activator::setName));
			usertypeDefinition.set("script", sol::property(&TES3::Activator::getScript));

			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition.set("model", sol::property(&TES3::Activator::getModelPath, &TES3::Activator::setModelPath));

			// Finish up our usertype.
			state.set_usertype("tes3activator", usertypeDefinition);
		}
	}
}

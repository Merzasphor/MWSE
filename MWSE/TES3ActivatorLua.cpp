#include "TES3ActivatorLua.h"

#include "sol.hpp"
#include "LuaManager.h"

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

			// Functions exposed as properties.
			usertypeDefinition.set("model", sol::property(&TES3::Activator::getModelPath, &TES3::Activator::setModelPathString));
			usertypeDefinition.set("name", sol::property(&TES3::Activator::getName, &TES3::Activator::setName));
			usertypeDefinition.set("script", sol::property(&TES3::Activator::getScript));

			// Finish up our usertype.
			state.set_usertype("TES3Activator", usertypeDefinition);
		}
	}
}

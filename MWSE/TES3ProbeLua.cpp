#include "TES3ProbeLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Probe.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Probe() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Probe>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
			setUserdataForPhysicalObject(usertypeDefinition);

			// Allow object to be converted to strings using their object ID.
			usertypeDefinition.set(sol::meta_function::to_string, &TES3::Probe::getObjectID);

			// Basic property binding.
			usertypeDefinition.set("condition", &TES3::Probe::maxCondition);
			usertypeDefinition.set("quality", &TES3::Probe::quality);
			usertypeDefinition.set("value", &TES3::Probe::value);
			usertypeDefinition.set("weight", &TES3::Probe::weight);

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("script", sol::readonly_property([](TES3::Probe& self) { return makeLuaObject(self.getScript()); }));

			// Functions exposed as properties.
			usertypeDefinition.set("icon", sol::property(
				&TES3::Probe::getIconPath,
				[](TES3::Probe& self, const char* value) { if (strlen(value) < 32) strcpy(self.icon, value); }
			));
			usertypeDefinition.set("mesh", sol::property(&TES3::Probe::getModelPath, &TES3::Probe::setModelPath));
			usertypeDefinition.set("name", sol::property(&TES3::Probe::getName, &TES3::Probe::setName));

			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition.set("model", sol::property(&TES3::Probe::getModelPath, &TES3::Probe::setModelPath));

			// Finish up our usertype.
			state.set_usertype("tes3lockpick", usertypeDefinition);
		}
	}
}

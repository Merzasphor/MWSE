#include "TES3ProbeLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Probe.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Probe() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::Probe>("tes3lockpick");
			usertypeDefinition["new"] = sol::no_constructor;

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition[sol::base_classes] = sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>();
			setUserdataForPhysicalObject(usertypeDefinition);

			// Allow object to be converted to strings using their object ID.
			usertypeDefinition[sol::meta_function::to_string] = &TES3::Probe::getObjectID;

			// Basic property binding.
			usertypeDefinition["maxCondition"] = &TES3::Probe::maxCondition;
			usertypeDefinition["quality"] = &TES3::Probe::quality;
			usertypeDefinition["value"] = &TES3::Probe::value;
			usertypeDefinition["weight"] = &TES3::Probe::weight;

			// Access to other objects that need to be packaged.
			usertypeDefinition["script"] = sol::readonly_property([](TES3::Probe& self) { return makeLuaObject(self.getScript()); });

			// Functions exposed as properties.
			usertypeDefinition["icon"] = sol::property(
				&TES3::Probe::getIconPath,
				[](TES3::Probe& self, const char* value) { if (strlen(value) < 32) strcpy(self.icon, value); }
			);
			usertypeDefinition["mesh"] = sol::property(&TES3::Probe::getModelPath, &TES3::Probe::setModelPath);
			usertypeDefinition["name"] = sol::property(&TES3::Probe::getName, &TES3::Probe::setName);

			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition["condition"] = &TES3::Probe::maxCondition;
			usertypeDefinition["model"] = sol::property(&TES3::Probe::getModelPath, &TES3::Probe::setModelPath);
		}
	}
}

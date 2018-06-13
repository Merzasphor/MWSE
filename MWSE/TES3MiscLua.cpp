#include "TES3MiscLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Misc.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Misc() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Misc>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());

			// Allow object to be converted to strings using their object ID.
			usertypeDefinition.set(sol::meta_function::to_string, &TES3::Misc::getObjectID);

			// Basic property binding.
			usertypeDefinition.set("value", &TES3::Misc::value);
			usertypeDefinition.set("weight", &TES3::Misc::weight);

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("script", sol::readonly_property([](TES3::Misc& self) { return makeLuaObject(self.getScript()); }));

			// Functions exposed as properties.
			usertypeDefinition.set("icon", sol::property(
				&TES3::Misc::getIconPath,
				[](TES3::Misc& self, const char* value) { if (strlen(value) < 32) tes3::setDataString(&self.icon, value); }
			));
			usertypeDefinition.set("model", sol::property(&TES3::Misc::getModelPath, &TES3::Misc::setModelPath));
			usertypeDefinition.set("name", sol::property(&TES3::Misc::getName, &TES3::Misc::setName));

			// Finish up our usertype.
			state.set_usertype("tes3misc", usertypeDefinition);
		}
	}
}

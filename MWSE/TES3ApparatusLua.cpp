#include "TES3ApparatusLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Apparatus.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Apparatus() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Apparatus>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
			setUserdataForPhysicalObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("type", &TES3::Apparatus::type);
			usertypeDefinition.set("quality", &TES3::Apparatus::quality);
			usertypeDefinition.set("value", &TES3::Apparatus::value);
			usertypeDefinition.set("weight", &TES3::Apparatus::weight);

			// Functions exposed as properties.
			usertypeDefinition.set("icon", sol::property(
				&TES3::Apparatus::getIconPath,
				[](TES3::Apparatus& self, const char* value) { if (strlen(value) < 32) strcpy(self.texture, value); }
			));
			usertypeDefinition.set("mesh", sol::property(&TES3::Apparatus::getModelPath, &TES3::Apparatus::setModelPath));
			usertypeDefinition.set("name", sol::property(&TES3::Apparatus::getName, &TES3::Apparatus::setName));
			usertypeDefinition.set("script", sol::property(&TES3::Apparatus::getScript));

			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition.set("model", sol::property(&TES3::Apparatus::getModelPath, &TES3::Apparatus::setModelPath));

			// Finish up our usertype.
			state.set_usertype("tes3apparatus", usertypeDefinition);
		}
	}
}

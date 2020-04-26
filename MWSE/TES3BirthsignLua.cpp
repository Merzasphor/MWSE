#include "TES3Birthsign.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

namespace mwse {
	namespace lua {
		void bindTES3Birthsign() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Birthsign>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());
			setUserdataForBaseObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("name", sol::readonly_property(&TES3::Birthsign::getName));
			usertypeDefinition.set("texturePath", &TES3::Birthsign::texturePath);
			usertypeDefinition.set("spells", sol::readonly_property(&TES3::Birthsign::spellList));

			usertypeDefinition.set("description", sol::readonly_property(&TES3::Birthsign::getAndFreeDescription));

			// Finish up our usertype.
			state.set_usertype("tes3birthsign", usertypeDefinition);
		}
	}
}

#include "TES3MoonLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Moon.h"
#include "TES3WeatherController.h"

namespace mwse {
	namespace lua {
		void bindTES3Moon() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Moon>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Basic property binding.
			usertypeDefinition.set("phase", &TES3::Moon::phase);
			usertypeDefinition.set("isRed", &TES3::Moon::moonIsRed);
			usertypeDefinition.set("weatherController", sol::readonly_property(&TES3::Moon::weatherController));

			// Functions exposed as properties.
			usertypeDefinition.set("texture", sol::property(
				[](TES3::Moon& self) { return self.texture; },
				[](TES3::Moon& self, const char* value) { if (strlen(value) < 32) tes3::setDataString(&self.texture, value); }
			));

			// Finish up our usertype.
			state.set_usertype("tes3moon", usertypeDefinition);
		}
	}
}

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
			usertypeDefinition.set("axisOffset", &TES3::Moon::axisOffset);
			usertypeDefinition.set("dailyIncrement", &TES3::Moon::dailyIncrement);
			usertypeDefinition.set("fadeEndAngle", &TES3::Moon::fadeEndAngle);
			usertypeDefinition.set("fadeInFinish", &TES3::Moon::fadeInFinish);
			usertypeDefinition.set("fadeInStart", &TES3::Moon::fadeInStart);
			usertypeDefinition.set("fadeOutFinish", &TES3::Moon::fadeOutFinish);
			usertypeDefinition.set("fadeOutStart", &TES3::Moon::fadeOutStart);
			usertypeDefinition.set("fadeStartAngle", &TES3::Moon::fadeStartAngle);
			usertypeDefinition.set("index", sol::readonly_property(&TES3::Moon::index));
			usertypeDefinition.set("isRed", &TES3::Moon::moonIsRed);
			usertypeDefinition.set("phase", &TES3::Moon::phase);
			usertypeDefinition.set("shadowEarlyFadeAngle", &TES3::Moon::shadowEarlyFadeAngle);
			usertypeDefinition.set("speed", &TES3::Moon::speed);
			usertypeDefinition.set("weatherController", sol::readonly_property(&TES3::Moon::weatherController));

			// Functions exposed as properties.
			usertypeDefinition.set("texture", sol::readonly_property([](TES3::Moon& self) -> const char* { return self.texturePath; }));

			// Finish up our usertype.
			state.set_usertype("tes3moon", usertypeDefinition);
		}
	}
}

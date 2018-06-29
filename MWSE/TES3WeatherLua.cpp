#include "TES3WeatherLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Weather.h"

namespace mwse {
	namespace lua {
		void bindTES3Weather() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Weather>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Basic property binding.
			usertypeDefinition.set("ambientDayColor", &TES3::Weather::ambientDayCol);
			usertypeDefinition.set("ambientNightColor", &TES3::Weather::ambientNightCol);
			usertypeDefinition.set("ambientSunriseColor", &TES3::Weather::ambientSunriseCol);
			usertypeDefinition.set("ambientSunsetColor", &TES3::Weather::ambientSunsetCol);
			usertypeDefinition.set("cloudsMaxPercent", &TES3::Weather::cloudsMaxPercent);
			usertypeDefinition.set("cloudsSpeed", &TES3::Weather::cloudsSpeed);
			usertypeDefinition.set("cloudTexture", &TES3::Weather::texturePathCloud);
			usertypeDefinition.set("fogDayColor", &TES3::Weather::fogDayCol);
			usertypeDefinition.set("fogNightColor", &TES3::Weather::fogNightCol);
			usertypeDefinition.set("fogSunriseColor", &TES3::Weather::fogSunriseCol);
			usertypeDefinition.set("fogSunsetColor", &TES3::Weather::fogSunsetCol);
			usertypeDefinition.set("glareView", &TES3::Weather::glareView);
			usertypeDefinition.set("index", sol::readonly_property(&TES3::Weather::index));
			usertypeDefinition.set("landFogDayDepth", &TES3::Weather::landFogDayDepth);
			usertypeDefinition.set("landFogNightDepth", &TES3::Weather::landFogNightDepth);
			usertypeDefinition.set("skyDayColor", &TES3::Weather::skyDayCol);
			usertypeDefinition.set("skyNightColor", &TES3::Weather::skyNightCol);
			usertypeDefinition.set("skySunriseColor", &TES3::Weather::skySunriseCol);
			usertypeDefinition.set("skySunsetColor", &TES3::Weather::skySunsetCol);
			usertypeDefinition.set("soundAmbientLoops", &TES3::Weather::soundIDAmbientLoop);
			usertypeDefinition.set("sunDayColor", &TES3::Weather::sunDayCol);
			usertypeDefinition.set("sundiscSunsetColor", &TES3::Weather::sundiscSunsetCol);
			usertypeDefinition.set("sunNightColor", &TES3::Weather::sunNightCol);
			usertypeDefinition.set("sunSunriseColor", &TES3::Weather::sunSunriseCol);
			usertypeDefinition.set("sunSunsetColor", &TES3::Weather::sunSunsetCol);
			usertypeDefinition.set("transitionDelta", &TES3::Weather::transitionDelta);
			usertypeDefinition.set("underwaterSoundActive", &TES3::Weather::flagUnderwaterSoundActive);
			usertypeDefinition.set("windSpeed", &TES3::Weather::windSpeed);

			// Finish up our usertype.
			state.set_usertype("tes3weather", usertypeDefinition);
		}
	}
}

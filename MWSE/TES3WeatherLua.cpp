#include "TES3WeatherLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Weather.h"

namespace mwse {
	namespace lua {
		void bindTES3Weather() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::Weather>("TES3Weather",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"transitionDelta", &TES3::Weather::transitionDelta,

				"ambientSunriseColor", &TES3::Weather::ambientSunriseCol,
				"ambientDayColor", &TES3::Weather::ambientDayCol,
				"ambientSunsetColor", &TES3::Weather::ambientSunsetCol,
				"ambientNightColor", &TES3::Weather::ambientNightCol,
				"fogSunriseColor", &TES3::Weather::fogSunriseCol,
				"fogDayColor", &TES3::Weather::fogDayCol,
				"fogSunsetColor", &TES3::Weather::fogSunsetCol,
				"fogNightColor", &TES3::Weather::fogNightCol,
				"skySunriseColor", &TES3::Weather::skySunriseCol,
				"skyDayColor", &TES3::Weather::skyDayCol,
				"skySunsetColor", &TES3::Weather::skySunsetCol,
				"skyNightColor", &TES3::Weather::skyNightCol,
				"sunSunriseColor", &TES3::Weather::sunSunriseCol,
				"sunDayColor", &TES3::Weather::sunDayCol,
				"sunSunsetColor", &TES3::Weather::sunSunsetCol,
				"sunNightColor", &TES3::Weather::sunNightCol,
				"sundiscSunsetColor", &TES3::Weather::sundiscSunsetCol,

				"glareView", &TES3::Weather::glareView,
				"cloudsMaxPercent", &TES3::Weather::cloudsMaxPercent,
				"landFogDayDepth", &TES3::Weather::landFogDayDepth,
				"landFogNightDepth", &TES3::Weather::landFogNightDepth,
				"cloudsSpeed", &TES3::Weather::cloudsSpeed,
				"windSpeed", &TES3::Weather::windSpeed,

				"cloudTexture", &TES3::Weather::texturePathCloud,

				"underwaterSoundActive", &TES3::Weather::flagUnderwaterSoundActive,
				"soundAmbientLoops", &TES3::Weather::soundIDAmbientLoop

				);
		}
	}
}

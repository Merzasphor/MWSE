#pragma once

#include "LuaUtil.h"

#include "TES3Sound.h"
#include "TES3Weather.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForWeather(sol::simple_usertype<T>& usertypeDefinition) {
			// Basic property binding.
			usertypeDefinition.set("ambientDayColor", sol::readonly_property(&TES3::Weather::ambientDayCol));
			usertypeDefinition.set("ambientNightColor", sol::readonly_property(&TES3::Weather::ambientNightCol));
			usertypeDefinition.set("ambientPlaying", sol::readonly_property(&TES3::Weather::ambientPlaying));
			usertypeDefinition.set("ambientSunriseColor", sol::readonly_property(&TES3::Weather::ambientSunriseCol));
			usertypeDefinition.set("ambientSunsetColor", sol::readonly_property(&TES3::Weather::ambientSunsetCol));
			usertypeDefinition.set("cloudsMaxPercent", &TES3::Weather::cloudsMaxPercent);
			usertypeDefinition.set("cloudsSpeed", &TES3::Weather::cloudsSpeed);
			usertypeDefinition.set("controller", sol::readonly_property(&TES3::Weather::controller));
			usertypeDefinition.set("fogDayColor", sol::readonly_property(&TES3::Weather::fogDayCol));
			usertypeDefinition.set("fogNightColor", sol::readonly_property(&TES3::Weather::fogNightCol));
			usertypeDefinition.set("fogSunriseColor", sol::readonly_property(&TES3::Weather::fogSunriseCol));
			usertypeDefinition.set("fogSunsetColor", sol::readonly_property(&TES3::Weather::fogSunsetCol));
			usertypeDefinition.set("glareView", &TES3::Weather::glareView);
			usertypeDefinition.set("index", sol::readonly_property(&TES3::Weather::index));
			usertypeDefinition.set("landFogDayDepth", &TES3::Weather::landFogDayDepth);
			usertypeDefinition.set("landFogNightDepth", &TES3::Weather::landFogNightDepth);
			usertypeDefinition.set("skyDayColor", sol::readonly_property(&TES3::Weather::skyDayCol));
			usertypeDefinition.set("skyNightColor", sol::readonly_property(&TES3::Weather::skyNightCol));
			usertypeDefinition.set("skySunriseColor", sol::readonly_property(&TES3::Weather::skySunriseCol));
			usertypeDefinition.set("skySunsetColor", sol::readonly_property(&TES3::Weather::skySunsetCol));
			usertypeDefinition.set("sunDayColor", sol::readonly_property(&TES3::Weather::sunDayCol));
			usertypeDefinition.set("sundiscSunsetColor", sol::readonly_property(&TES3::Weather::sundiscSunsetCol));
			usertypeDefinition.set("sunNightColor", sol::readonly_property(&TES3::Weather::sunNightCol));
			usertypeDefinition.set("sunSunriseColor", sol::readonly_property(&TES3::Weather::sunSunriseCol));
			usertypeDefinition.set("sunSunsetColor", sol::readonly_property(&TES3::Weather::sunSunsetCol));
			usertypeDefinition.set("transitionDelta", &TES3::Weather::transitionDelta);
			usertypeDefinition.set("underwaterSoundState", sol::readonly_property(&TES3::Weather::underwaterSoundState));
			usertypeDefinition.set("windSpeed", &TES3::Weather::windSpeed);

			// Binding for IDs and paths.
			usertypeDefinition.set("ambientLoopSoundId", sol::property(
				[](TES3::Weather& self) { return self.soundIDAmbientLoop; },
				[](TES3::Weather& self, const char* value) { if (strlen(value) < 260) strcpy(self.soundIDAmbientLoop, value); }
			));
			usertypeDefinition.set("cloudTexture", sol::property(
				[](TES3::Weather& self) { return self.texturePathCloud; },
				[](TES3::Weather& self, const char* value) { if (strlen(value) < 260) strcpy(self.texturePathCloud, value); }
			));

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("ambientLoopSound", sol::readonly_property([](TES3::Weather& self) { return makeLuaObject(self.soundAmbientLoop); }));
		}

		void bindTES3Weather();
	}
}

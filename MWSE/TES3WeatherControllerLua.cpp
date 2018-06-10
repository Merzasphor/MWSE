#include "TES3WeatherControllerLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Moon.h"
#include "TES3Weather.h"
#include "TES3WeatherController.h"

namespace mwse {
	namespace lua {
		void bindTES3WeatherController() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::WeatherController>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Basic property binding.
			usertypeDefinition.set("currentFogColor", &TES3::WeatherController::currentSkyColor);
			usertypeDefinition.set("currentSkyColor", &TES3::WeatherController::currentSkyColor);
			usertypeDefinition.set("currentWeather", &TES3::WeatherController::currentWeather);
			usertypeDefinition.set("daysRemaining", &TES3::WeatherController::daysRemaining);
			usertypeDefinition.set("hoursBetweenWeatherChanges", &TES3::WeatherController::hoursBetweenWeatherChanges);
			usertypeDefinition.set("hoursRemaining", &TES3::WeatherController::hoursRemaining);
			usertypeDefinition.set("masser", sol::readonly_property(&TES3::WeatherController::moonMasser));
			usertypeDefinition.set("nextWeather", &TES3::WeatherController::nextWeather);
			usertypeDefinition.set("secunda", sol::readonly_property(&TES3::WeatherController::moonSecunda));
			usertypeDefinition.set("soundUnderwater", &TES3::WeatherController::soundUnderwater);
			usertypeDefinition.set("sunglareFaderAngleMax", &TES3::WeatherController::sunglareFaderAngleMax);
			usertypeDefinition.set("sunglareFaderColor", &TES3::WeatherController::sunglareFaderCol);
			usertypeDefinition.set("sunglareFaderMax", &TES3::WeatherController::sunglareFaderMax);
			usertypeDefinition.set("sunriseDuration", &TES3::WeatherController::sunriseDuration);
			usertypeDefinition.set("sunriseHour", &TES3::WeatherController::sunriseHour);
			usertypeDefinition.set("sunsetDuration", &TES3::WeatherController::sunsetDuration);
			usertypeDefinition.set("sunsetHour", &TES3::WeatherController::sunsetHour);
			usertypeDefinition.set("timescaleClouds", &TES3::WeatherController::timescaleClouds);
			usertypeDefinition.set("transitionScalar", &TES3::WeatherController::transitionScalar);
			usertypeDefinition.set("underwaterColor", &TES3::WeatherController::underwaterCol);
			usertypeDefinition.set("underwaterColorWeight", &TES3::WeatherController::underwaterColWeight);
			usertypeDefinition.set("underwaterDayFog", &TES3::WeatherController::underwaterDayFog);
			usertypeDefinition.set("underwaterIndoorFog", &TES3::WeatherController::underwaterIndoorFog);
			usertypeDefinition.set("underwaterNightFog", &TES3::WeatherController::underwaterNightFog);
			usertypeDefinition.set("underwaterSunriseFog", &TES3::WeatherController::underwaterSunriseFog);
			usertypeDefinition.set("underwaterSunsetFog", &TES3::WeatherController::underwaterSunsetFog);
			usertypeDefinition.set("windDirection", &TES3::WeatherController::currentSkyColor);

			// Indirect bindings to unions and arrays.
			usertypeDefinition.set("weathers", sol::readonly_property([](TES3::WeatherController& self) { return std::ref(self.arrayWeathers); }));

			// Finish up our usertype.
			state.set_usertype("tes3weatherController", usertypeDefinition);
		}
	}
}

#include "TES3WeatherControllerLua.h"

#include "LuaManager.h"

#include "TES3WeatherController.h"

#include "TES3Moon.h"
#include "TES3Weather.h"

namespace mwse {
	namespace lua {
		void bindTES3WeatherController() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::WeatherController>("TES3WeatherController",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"currentWeather", &TES3::WeatherController::currentWeather,
				"nextWeather", &TES3::WeatherController::nextWeather,
				"weathers", sol::readonly_property([](TES3::WeatherController* self) { return std::ref(self->arrayWeathers); }),

				"daysRemaining", &TES3::WeatherController::daysRemaining,
				"hoursBetweenWeatherChanges", &TES3::WeatherController::hoursBetweenWeatherChanges,
				"hoursRemaining", &TES3::WeatherController::hoursRemaining,
				"transitionScalar", &TES3::WeatherController::transitionScalar,

				"secunda", sol::readonly_property(&TES3::WeatherController::moonSecunda),
				"masser", sol::readonly_property(&TES3::WeatherController::moonMasser),
				
				"timescaleClouds", &TES3::WeatherController::timescaleClouds,
				"sunglareFaderMax", &TES3::WeatherController::sunglareFaderMax,
				"sunglareFaderAngleMax", &TES3::WeatherController::sunglareFaderAngleMax,
				"sunriseHour", &TES3::WeatherController::sunriseHour,
				"sunsetHour", &TES3::WeatherController::sunsetHour,
				"sunriseDuration", &TES3::WeatherController::sunriseDuration,
				"sunsetDuration", &TES3::WeatherController::sunsetDuration,

				"underwaterSunriseFog", &TES3::WeatherController::underwaterSunriseFog,
				"underwaterDayFog", &TES3::WeatherController::underwaterDayFog,
				"underwaterSunsetFog", &TES3::WeatherController::underwaterSunsetFog,
				"underwaterNightFog", &TES3::WeatherController::underwaterNightFog,
				"underwaterIndoorFog", &TES3::WeatherController::underwaterIndoorFog,
				"underwaterColor", &TES3::WeatherController::underwaterCol,
				"underwaterColorWeight", &TES3::WeatherController::underwaterColWeight,
				"sunglareFaderColor", &TES3::WeatherController::sunglareFaderCol,
				"soundUnderwater", &TES3::WeatherController::soundUnderwater

				);
		}
	}
}

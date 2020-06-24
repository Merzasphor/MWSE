#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIDirectionalLight.h"
#include "NINode.h"
#include "TES3Moon.h"
#include "TES3Region.h"
#include "TES3Weather.h"
#include "TES3WeatherController.h"
#include "TES3WeatherControllerLua.h"

namespace mwse {
	namespace lua {
		void bindTES3WeatherController() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::WeatherController>("tes3weatherController");
			usertypeDefinition["new"] = sol::no_constructor;

			// Basic property binding.
			usertypeDefinition["currentFogColor"] = &TES3::WeatherController::currentFogColor;
			usertypeDefinition["currentSkyColor"] = &TES3::WeatherController::currentSkyColor;
			usertypeDefinition["currentWeather"] = sol::readonly_property(&TES3::WeatherController::currentWeather);
			usertypeDefinition["hoursBetweenWeatherChanges"] = &TES3::WeatherController::hoursBetweenWeatherChanges;
			usertypeDefinition["daysRemaining"] = &TES3::WeatherController::daysRemaining;
			usertypeDefinition["hoursRemaining"] = &TES3::WeatherController::hoursRemaining;
			usertypeDefinition["masser"] = sol::readonly_property(&TES3::WeatherController::moonMasser);
			usertypeDefinition["secunda"] = sol::readonly_property(&TES3::WeatherController::moonSecunda);
			usertypeDefinition["lastActiveRegion"] = sol::readonly_property(&TES3::WeatherController::lastActiveRegion);
			usertypeDefinition["nextWeather"] = sol::readonly_property(&TES3::WeatherController::nextWeather);
			usertypeDefinition["sceneRainRoot"] = sol::readonly_property(&TES3::WeatherController::sgRainRoot);
			usertypeDefinition["sceneSkyLight"] = sol::readonly_property(&TES3::WeatherController::sgSkyLight);
			usertypeDefinition["sceneSkyRoot"] = sol::readonly_property(&TES3::WeatherController::sgSkyRoot);
			usertypeDefinition["sceneSnowRoot"] = sol::readonly_property(&TES3::WeatherController::sgSnowRoot);
			usertypeDefinition["sceneStormRoot"] = sol::readonly_property(&TES3::WeatherController::sgStormRoot);
			usertypeDefinition["sceneSunBase"] = sol::readonly_property(&TES3::WeatherController::sgSunBase);
			usertypeDefinition["sceneSunGlare"] = sol::readonly_property(&TES3::WeatherController::sgSunGlare);
			usertypeDefinition["sceneSunVis"] = sol::readonly_property(&TES3::WeatherController::sgSunVis);
			usertypeDefinition["sunglareFaderAngleMax"] = &TES3::WeatherController::sunglareFaderAngleMax;
			usertypeDefinition["sunglareFaderColor"] = &TES3::WeatherController::sunglareFaderCol;
			usertypeDefinition["sunglareFaderMax"] = &TES3::WeatherController::sunglareFaderMax;
			usertypeDefinition["sunriseDuration"] = &TES3::WeatherController::sunriseDuration;
			usertypeDefinition["sunriseHour"] = &TES3::WeatherController::sunriseHour;
			usertypeDefinition["sunsetDuration"] = &TES3::WeatherController::sunsetDuration;
			usertypeDefinition["sunsetHour"] = &TES3::WeatherController::sunsetHour;
			usertypeDefinition["timescaleClouds"] = &TES3::WeatherController::bTimescaleClouds;
			usertypeDefinition["transitionScalar"] = &TES3::WeatherController::transitionScalar;
			usertypeDefinition["underwaterColor"] = &TES3::WeatherController::underwaterCol;
			usertypeDefinition["underwaterColorWeight"] = &TES3::WeatherController::underwaterColWeight;
			usertypeDefinition["underwaterDayFog"] = &TES3::WeatherController::underwaterDayFog;
			usertypeDefinition["underwaterIndoorFog"] = &TES3::WeatherController::underwaterIndoorFog;
			usertypeDefinition["underwaterNightFog"] = &TES3::WeatherController::underwaterNightFog;
			usertypeDefinition["underwaterSunriseFog"] = &TES3::WeatherController::underwaterSunriseFog;
			usertypeDefinition["underwaterSunsetFog"] = &TES3::WeatherController::underwaterSunsetFog;
			usertypeDefinition["weathers"] = sol::readonly_property(&TES3::WeatherController::getWeathers);
			usertypeDefinition["windVelocityCurrWeather"] = &TES3::WeatherController::windVelocityCurrWeather;
			usertypeDefinition["windVelocityNextWeather"] = &TES3::WeatherController::windVelocityNextWeather;

			// Basic function bindings.
			usertypeDefinition["calcSunDamageScalar"] = &TES3::WeatherController::calcSunDamageScalar;
			usertypeDefinition["switchImmediate"] = &TES3::WeatherController::switchImmediate;
			usertypeDefinition["switchTransition"] = &TES3::WeatherController::switchTransition;
			usertypeDefinition["updateVisuals"] = &TES3::WeatherController::updateVisuals;
		}
	}
}

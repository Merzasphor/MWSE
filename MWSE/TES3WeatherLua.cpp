#include "TES3WeatherLua.h"

#include "LuaManager.h"

#include "TES3WeatherAsh.h"
#include "TES3WeatherBlight.h"
#include "TES3WeatherBlizzard.h"
#include "TES3WeatherClear.h"
#include "TES3WeatherCloudy.h"
#include "TES3WeatherController.h"
#include "TES3WeatherFoggy.h"
#include "TES3WeatherOvercast.h"
#include "TES3WeatherRain.h"
#include "TES3WeatherSnow.h"
#include "TES3WeatherThunder.h"

namespace mwse {
	namespace lua {
		void bindTES3Weather() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::Weather
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Weather>("tes3weather");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["ambientDayColor"] = sol::readonly_property(&TES3::Weather::ambientDayCol);
				usertypeDefinition["ambientLoopSound"] = &TES3::Weather::soundAmbientLoop;
				usertypeDefinition["ambientLoopSoundId"] = sol::property(&TES3::Weather::soundIDAmbientLoop, &TES3::Weather::setAmbientLoopSoundID);
				usertypeDefinition["ambientNightColor"] = sol::readonly_property(&TES3::Weather::ambientNightCol);
				usertypeDefinition["ambientPlaying"] = sol::readonly_property(&TES3::Weather::ambientPlaying);
				usertypeDefinition["ambientSunriseColor"] = sol::readonly_property(&TES3::Weather::ambientSunriseCol);
				usertypeDefinition["ambientSunsetColor"] = sol::readonly_property(&TES3::Weather::ambientSunsetCol);
				usertypeDefinition["cloudsMaxPercent"] = &TES3::Weather::cloudsMaxPercent;
				usertypeDefinition["cloudsSpeed"] = &TES3::Weather::cloudsSpeed;
				usertypeDefinition["controller"] = sol::readonly_property(&TES3::Weather::controller);
				usertypeDefinition["fogDayColor"] = sol::readonly_property(&TES3::Weather::fogDayCol);
				usertypeDefinition["fogNightColor"] = sol::readonly_property(&TES3::Weather::fogNightCol);
				usertypeDefinition["fogSunriseColor"] = sol::readonly_property(&TES3::Weather::fogSunriseCol);
				usertypeDefinition["fogSunsetColor"] = sol::readonly_property(&TES3::Weather::fogSunsetCol);
				usertypeDefinition["glareView"] = &TES3::Weather::glareView;
				usertypeDefinition["index"] = sol::readonly_property(&TES3::Weather::index);
				usertypeDefinition["landFogDayDepth"] = &TES3::Weather::landFogDayDepth;
				usertypeDefinition["landFogNightDepth"] = &TES3::Weather::landFogNightDepth;
				usertypeDefinition["skyDayColor"] = sol::readonly_property(&TES3::Weather::skyDayCol);
				usertypeDefinition["skyNightColor"] = sol::readonly_property(&TES3::Weather::skyNightCol);
				usertypeDefinition["skySunriseColor"] = sol::readonly_property(&TES3::Weather::skySunriseCol);
				usertypeDefinition["skySunsetColor"] = sol::readonly_property(&TES3::Weather::skySunsetCol);
				usertypeDefinition["sunDayColor"] = sol::readonly_property(&TES3::Weather::sunDayCol);
				usertypeDefinition["sundiscSunsetColor"] = sol::readonly_property(&TES3::Weather::sundiscSunsetCol);
				usertypeDefinition["sunNightColor"] = sol::readonly_property(&TES3::Weather::sunNightCol);
				usertypeDefinition["sunSunriseColor"] = sol::readonly_property(&TES3::Weather::sunSunriseCol);
				usertypeDefinition["sunSunsetColor"] = sol::readonly_property(&TES3::Weather::sunSunsetCol);
				usertypeDefinition["transitionDelta"] = &TES3::Weather::transitionDelta;
				usertypeDefinition["underwaterSoundState"] = sol::readonly_property(&TES3::Weather::underwaterSoundState);
				usertypeDefinition["windSpeed"] = &TES3::Weather::windSpeed;
			}
			

			// Binding for TES3::WeatherAsh
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::WeatherAsh>("tes3weatherAsh");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Weather>();
				setUserdataForWeather(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["threshold"] = &TES3::WeatherAsh::stormThreshold;
			}

			// Binding for TES3::WeatherBlight
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::WeatherBlight>("tes3weatherBlight");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Weather>();
				setUserdataForWeather(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["blightDiseaseChance"] = &TES3::WeatherBlight::diseaseChance;
				usertypeDefinition["blightDiseases"] = sol::readonly_property(&TES3::WeatherBlight::blightDiseases);
				usertypeDefinition["threshold"] = &TES3::WeatherBlight::stormThreshold;
			}

			// Binding for TES3::WeatherBlizzard
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::WeatherBlizzard>("tes3weatherBlizzard");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Weather>();
				setUserdataForWeather(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["threshold"] = &TES3::WeatherBlizzard::stormThreshold;
			}

			// Binding for TES3::WeatherClear
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::WeatherClear>("tes3weatherClear");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Weather>();
				setUserdataForWeather(usertypeDefinition);
			}

			// Binding for TES3::WeatherCloudy
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::WeatherCloudy>("tes3weatherCloudy");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Weather>();
				setUserdataForWeather(usertypeDefinition);
			}

			// Binding for TES3::WeatherFoggy
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::WeatherFoggy>("tes3weatherFoggy");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Weather>();
				setUserdataForWeather(usertypeDefinition);
			}

			// Binding for TES3::WeatherOvercast
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::WeatherOvercast>("tes3weatherOvercast");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Weather>();
				setUserdataForWeather(usertypeDefinition);
			}

			// Binding for TES3::WeatherRain
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::WeatherRain>("tes3weatherRain");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Weather>();
				setUserdataForWeather(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["maxParticles"] = &TES3::WeatherRain::raindropsMax;
				usertypeDefinition["particleEntranceSpeed"] = &TES3::WeatherRain::rainEntranceSpeed;
				usertypeDefinition["particleHeightMax"] = &TES3::WeatherRain::rainHeightMax;
				usertypeDefinition["particleHeightMin"] = &TES3::WeatherRain::rainHeightMin;
				usertypeDefinition["particleRadius"] = &TES3::WeatherRain::rainRadius;
				usertypeDefinition["rainActive"] = sol::readonly_property(&TES3::WeatherRain::rainPlaying);
				usertypeDefinition["rainLoopSound"] = &TES3::WeatherRain::rainLoopSound;
				usertypeDefinition["rainLoopSoundId"] = sol::property(&TES3::WeatherRain::soundIDRainLoop, &TES3::WeatherRain::setRainLoopSoundID);
				usertypeDefinition["threshold"] = &TES3::WeatherRain::rainThreshold;
			}

			// Binding for TES3::WeatherSnow
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::WeatherSnow>("tes3weatherSnow");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Weather>();
				setUserdataForWeather(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["maxParticles"] = &TES3::WeatherSnow::snowflakesMax;
				usertypeDefinition["particleEntranceSpeed"] = &TES3::WeatherSnow::snowEntranceSpeed;
				usertypeDefinition["particleHeightMax"] = &TES3::WeatherSnow::snowHeightMax;
				usertypeDefinition["particleHeightMin"] = &TES3::WeatherSnow::snowHeightMin;
				usertypeDefinition["particleRadius"] = &TES3::WeatherSnow::snowRadius;
				usertypeDefinition["threshold"] = &TES3::WeatherSnow::snowThreshold;
			}

			// Binding for TES3::WeatherThunder
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::WeatherThunder>("tes3weatherThunder");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Weather>();
				setUserdataForWeather(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["flashDecrement"] = &TES3::WeatherThunder::flashDecrement;
				usertypeDefinition["maxParticles"] = &TES3::WeatherThunder::raindropsMax;
				usertypeDefinition["particleEntranceSpeed"] = &TES3::WeatherThunder::rainEntranceSpeed;
				usertypeDefinition["particleHeightMax"] = &TES3::WeatherThunder::rainHeightMax;
				usertypeDefinition["particleHeightMin"] = &TES3::WeatherThunder::rainHeightMin;
				usertypeDefinition["particleRadius"] = &TES3::WeatherThunder::rainRadius;
				usertypeDefinition["rainActive"] = &TES3::WeatherThunder::rainPlaying;
				usertypeDefinition["rainLoopSound"] = &TES3::WeatherThunder::rainLoopSound;
				usertypeDefinition["rainLoopSoundId"] = sol::property(&TES3::WeatherThunder::soundIdRainLoop, &TES3::WeatherThunder::setRainLoopSoundID);
				usertypeDefinition["threshold"] = &TES3::WeatherThunder::rainThreshold;
				usertypeDefinition["thunderFrequency"] = &TES3::WeatherThunder::thunderFrequency;
				usertypeDefinition["thunderSound1"] = &TES3::WeatherThunder::thunderSound1;
				usertypeDefinition["thunderSound1Id"] = sol::property(&TES3::WeatherThunder::soundIdThunder1, &TES3::WeatherThunder::setThunder1SoundID);
				usertypeDefinition["thunderSound2"] = &TES3::WeatherThunder::thunderSound2;
				usertypeDefinition["thunderSound2Id"] = sol::property(&TES3::WeatherThunder::soundIdThunder2, &TES3::WeatherThunder::setThunder2SoundID);
				usertypeDefinition["thunderSound3"] = &TES3::WeatherThunder::thunderSound3;
				usertypeDefinition["thunderSound3Id"] = sol::property(&TES3::WeatherThunder::soundIdThunder3, &TES3::WeatherThunder::setThunder3SoundID);
				usertypeDefinition["thunderSound4"] = &TES3::WeatherThunder::thunderSound4;
				usertypeDefinition["thunderSound4Id"] = sol::property(&TES3::WeatherThunder::soundIdThunder4, &TES3::WeatherThunder::setThunder4SoundID);
				usertypeDefinition["thunderSoundCount"] = &TES3::WeatherThunder::thunderSoundCount;
				usertypeDefinition["thunderThreshold"] = &TES3::WeatherThunder::thunderThreshold;
			}
		}
	}
}

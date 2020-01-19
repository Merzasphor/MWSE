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
				usertypeDefinition["threshold"] = &TES3::WeatherRain::rainThreshold;

				// Binding for IDs and paths.
				usertypeDefinition["rainLoopSoundId"] = sol::property(
					[](TES3::WeatherRain& self) { return self.soundIDRainLoop; },
					[](TES3::WeatherRain& self, const char* value) { if (strlen(value) < 260) strcpy(self.soundIDRainLoop, value); }
				);

				// Access to other objects that need to be packaged.
				usertypeDefinition["rainLoopSound"] = sol::readonly_property([](TES3::WeatherRain& self) { return self.rainLoopSound; });
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
				usertypeDefinition["threshold"] = &TES3::WeatherThunder::rainThreshold;
				usertypeDefinition["thunderFrequency"] = &TES3::WeatherThunder::thunderFrequency;
				usertypeDefinition["thunderSoundCount"] = &TES3::WeatherThunder::thunderSoundCount;
				usertypeDefinition["thunderThreshold"] = &TES3::WeatherThunder::thunderThreshold;

				// Binding for IDs and paths.
				usertypeDefinition["rainLoopSoundId"] = sol::property(
					[](TES3::WeatherThunder& self) { return self.soundIdRainLoop; },
					[](TES3::WeatherThunder& self, const char* value) { if (strlen(value) < 260) strcpy(self.soundIdRainLoop, value); }
				);
				usertypeDefinition["thunderSound1Id"] = sol::property(
					[](TES3::WeatherThunder& self) { return self.soundIdThunder1; },
					[](TES3::WeatherThunder& self, const char* value) { if (strlen(value) < 260) strcpy(self.soundIdThunder1, value); }
				);
				usertypeDefinition["thunderSound2Id"] = sol::property(
					[](TES3::WeatherThunder& self) { return self.soundIdThunder2; },
					[](TES3::WeatherThunder& self, const char* value) { if (strlen(value) < 260) strcpy(self.soundIdThunder2, value); }
				);
				usertypeDefinition["thunderSound3Id"] = sol::property(
					[](TES3::WeatherThunder& self) { return self.soundIdThunder3; },
					[](TES3::WeatherThunder& self, const char* value) { if (strlen(value) < 260) strcpy(self.soundIdThunder3, value); }
				);
				usertypeDefinition["thunderSound4Id"] = sol::property(
					[](TES3::WeatherThunder& self) { return self.soundIdThunder4; },
					[](TES3::WeatherThunder& self, const char* value) { if (strlen(value) < 260) strcpy(self.soundIdThunder4, value); }
				);

				// Access to other objects that need to be packaged.
				usertypeDefinition["rainLoopSound"] = sol::readonly_property([](TES3::WeatherThunder& self) { return self.rainLoopSound; });
				usertypeDefinition["thunderSound1"] = sol::readonly_property([](TES3::WeatherThunder& self) { return self.thunderSound1; });
				usertypeDefinition["thunderSound2"] = sol::readonly_property([](TES3::WeatherThunder& self) { return self.thunderSound2; });
				usertypeDefinition["thunderSound3"] = sol::readonly_property([](TES3::WeatherThunder& self) { return self.thunderSound3; });
				usertypeDefinition["thunderSound4"] = sol::readonly_property([](TES3::WeatherThunder& self) { return self.thunderSound4; });
			}
		}
	}
}

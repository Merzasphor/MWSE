#include "TES3WeatherLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Sound.h"
#include "TES3Weather.h"
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
			sol::state& state = LuaManager::getInstance().getState();

			// Bind TES3::Weather.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Weather>();
				usertypeDefinition.set("new", sol::no_constructor);

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

				// Finish up our usertype.
				state.set_usertype("tes3weather", usertypeDefinition);
			}

			// Binding for TES3::WeatherAsh
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::WeatherAsh>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Weather>());

				// Basic property binding.
				usertypeDefinition.set("threshold", &TES3::WeatherAsh::stormThreshold);

				// Finish up our usertype.
				state.set_usertype("tes3weatherAsh", usertypeDefinition);
			}

			// Binding for TES3::WeatherBlight
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::WeatherBlight>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Weather>());

				// Basic property binding.
				usertypeDefinition.set("blightDiseaseChance", &TES3::WeatherBlight::diseaseChance);
				usertypeDefinition.set("blightDiseases", sol::readonly_property(&TES3::WeatherBlight::blightDiseases));
				usertypeDefinition.set("threshold", &TES3::WeatherBlight::stormThreshold);

				// Finish up our usertype.
				state.set_usertype("tes3weatherBlight", usertypeDefinition);
			}

			// Binding for TES3::WeatherBlizzard
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::WeatherBlizzard>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Weather>());

				// Basic property binding.
				usertypeDefinition.set("threshold", &TES3::WeatherBlizzard::stormThreshold);

				// Finish up our usertype.
				state.set_usertype("tes3weatherBlizzard", usertypeDefinition);
			}

			// Binding for TES3::WeatherClear
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::WeatherClear>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Weather>());

				// Finish up our usertype.
				state.set_usertype("tes3weatherClear", usertypeDefinition);
			}

			// Binding for TES3::WeatherCloudy
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::WeatherCloudy>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Weather>());

				// Finish up our usertype.
				state.set_usertype("tes3weatherCloudy", usertypeDefinition);
			}

			// Binding for TES3::WeatherFoggy
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::WeatherFoggy>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Weather>());

				// Finish up our usertype.
				state.set_usertype("tes3weatherFoggy", usertypeDefinition);
			}

			// Binding for TES3::WeatherOvercast
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::WeatherOvercast>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Weather>());

				// Finish up our usertype.
				state.set_usertype("tes3weatherOvercast", usertypeDefinition);
			}

			// Binding for TES3::WeatherRain
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::WeatherRain>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Weather>());

				// Basic property binding.
				usertypeDefinition.set("maxParticles", &TES3::WeatherRain::raindropsMax);
				usertypeDefinition.set("particleEntranceSpeed", &TES3::WeatherRain::rainEntranceSpeed);
				usertypeDefinition.set("particleHeightMax", &TES3::WeatherRain::rainHeightMax);
				usertypeDefinition.set("particleHeightMin", &TES3::WeatherRain::rainHeightMin);
				usertypeDefinition.set("particleRadius", &TES3::WeatherRain::rainRadius);
				usertypeDefinition.set("rainActive", sol::readonly_property(&TES3::WeatherRain::rainPlaying));
				usertypeDefinition.set("threshold", &TES3::WeatherRain::rainThreshold);

				// Binding for IDs and paths.
				usertypeDefinition.set("rainLoopSoundId", sol::property(
					[](TES3::WeatherRain& self) { return self.soundIDRainLoop; },
					[](TES3::WeatherRain& self, const char* value) { if (strlen(value) < 260) strcpy(self.soundIDRainLoop, value); }
				));

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("rainLoopSound", sol::readonly_property([](TES3::WeatherRain& self) { return makeLuaObject(self.rainLoopSound); }));

				// Finish up our usertype.
				state.set_usertype("tes3weatherRain", usertypeDefinition);
			}

			// Binding for TES3::WeatherSnow
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::WeatherSnow>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Weather>());

				// Basic property binding.
				usertypeDefinition.set("maxParticles", &TES3::WeatherSnow::snowflakesMax);
				usertypeDefinition.set("particleEntranceSpeed", &TES3::WeatherSnow::snowEntranceSpeed);
				usertypeDefinition.set("particleHeightMax", &TES3::WeatherSnow::snowHeightMax);
				usertypeDefinition.set("particleHeightMin", &TES3::WeatherSnow::snowHeightMin);
				usertypeDefinition.set("particleRadius", &TES3::WeatherSnow::snowRadius);
				usertypeDefinition.set("threshold", &TES3::WeatherSnow::snowThreshold);

				// Finish up our usertype.
				state.set_usertype("tes3weatherSnow", usertypeDefinition);
			}

			// Binding for TES3::WeatherThunder
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::WeatherThunder>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Weather>());

				// Basic property binding.
				usertypeDefinition.set("flashDecrement", &TES3::WeatherThunder::flashDecrement);
				usertypeDefinition.set("maxParticles", &TES3::WeatherThunder::raindropsMax);
				usertypeDefinition.set("particleEntranceSpeed", &TES3::WeatherThunder::rainEntranceSpeed);
				usertypeDefinition.set("particleHeightMax", &TES3::WeatherThunder::rainHeightMax);
				usertypeDefinition.set("particleHeightMin", &TES3::WeatherThunder::rainHeightMin);
				usertypeDefinition.set("particleRadius", &TES3::WeatherThunder::rainRadius);
				usertypeDefinition.set("rainActive", &TES3::WeatherThunder::rainPlaying);
				usertypeDefinition.set("threshold", &TES3::WeatherThunder::rainThreshold);
				usertypeDefinition.set("thunderFrequency", &TES3::WeatherThunder::thunderFrequency);
				usertypeDefinition.set("thunderSoundCount", &TES3::WeatherThunder::thunderSoundCount);
				usertypeDefinition.set("thunderThreshold", &TES3::WeatherThunder::thunderThreshold);

				// Binding for IDs and paths.
				usertypeDefinition.set("rainLoopSoundId", sol::property(
					[](TES3::WeatherThunder& self) { return self.soundIdRainLoop; },
					[](TES3::WeatherThunder& self, const char* value) { if (strlen(value) < 260) strcpy(self.soundIdRainLoop, value); }
				));
				usertypeDefinition.set("thunderSound1Id", sol::property(
					[](TES3::WeatherThunder& self) { return self.soundIdThunder1; },
					[](TES3::WeatherThunder& self, const char* value) { if (strlen(value) < 260) strcpy(self.soundIdThunder1, value); }
				));
				usertypeDefinition.set("thunderSound2Id", sol::property(
					[](TES3::WeatherThunder& self) { return self.soundIdThunder2; },
					[](TES3::WeatherThunder& self, const char* value) { if (strlen(value) < 260) strcpy(self.soundIdThunder2, value); }
				));
				usertypeDefinition.set("thunderSound3Id", sol::property(
					[](TES3::WeatherThunder& self) { return self.soundIdThunder3; },
					[](TES3::WeatherThunder& self, const char* value) { if (strlen(value) < 260) strcpy(self.soundIdThunder3, value); }
				));
				usertypeDefinition.set("thunderSound4Id", sol::property(
					[](TES3::WeatherThunder& self) { return self.soundIdThunder4; },
					[](TES3::WeatherThunder& self, const char* value) { if (strlen(value) < 260) strcpy(self.soundIdThunder4, value); }
				));

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("rainLoopSound", sol::readonly_property([](TES3::WeatherThunder& self) { return makeLuaObject(self.rainLoopSound); }));
				usertypeDefinition.set("thunderSound1", sol::readonly_property([](TES3::WeatherThunder& self) { return makeLuaObject(self.thunderSound1); }));
				usertypeDefinition.set("thunderSound2", sol::readonly_property([](TES3::WeatherThunder& self) { return makeLuaObject(self.thunderSound2); }));
				usertypeDefinition.set("thunderSound3", sol::readonly_property([](TES3::WeatherThunder& self) { return makeLuaObject(self.thunderSound3); }));
				usertypeDefinition.set("thunderSound4", sol::readonly_property([](TES3::WeatherThunder& self) { return makeLuaObject(self.thunderSound4); }));

				// Finish up our usertype.
				state.set_usertype("tes3weatherThunder", usertypeDefinition);
			}
		}
	}
}

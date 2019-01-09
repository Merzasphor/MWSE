#include "TES3RegionLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3LeveledList.h"
#include "TES3Region.h"
#include "TES3Sound.h"
#include "TES3Weather.h"
#include "TES3WeatherController.h"
#include "TES3WorldController.h"

namespace mwse {
	namespace lua {
		void bindTES3Region() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::RegionSound
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::RegionSound>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("sound",  [](TES3::RegionSound& self) { return makeLuaObject(self.sound); });

				// Restrict chance [0-100].
				usertypeDefinition.set("chance", sol::property(
					[](TES3::RegionSound& self) { return self.chance; },
					[](TES3::RegionSound& self, int value)
				{
					if (value < 0) {
						value = 0;
					}
					else if (value > 100) {
						value = 100;
					}

					self.chance = value;
				}
				));

				// Finish up our usertype.
				state.set_usertype("tes3regionSound", usertypeDefinition);
			}

			// Binding for TES3::Region.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Region>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());
				setUserdataForBaseObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("name", sol::property([](TES3::Region& self) { return self.name; }));
				usertypeDefinition.set("sounds", sol::readonly_property(&TES3::Region::sounds));

				// Indirect bindings to unions and arrays.
				usertypeDefinition.set("weatherChances", sol::readonly_property([](TES3::Region& self) { return std::ref(self.weatherChances); }));

				// User-friendly access to weather chances.
				usertypeDefinition.set("weatherChanceAsh", sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Ash); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Ash, value); }
				));
				usertypeDefinition.set("weatherChanceBlight", sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Blight); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Blight, value); }
				));
				usertypeDefinition.set("weatherChanceBlizzard", sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Blizzard); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Blizzard, value); }
				));
				usertypeDefinition.set("weatherChanceClear", sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Clear); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Clear, value); }
				));
				usertypeDefinition.set("weatherChanceCloudy", sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Cloudy); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Cloudy, value); }
				));
				usertypeDefinition.set("weatherChanceFoggy", sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Foggy); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Foggy, value); }
				));
				usertypeDefinition.set("weatherChanceOvercast", sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Overcast); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Overcast, value); }
				));
				usertypeDefinition.set("weatherChanceRain", sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Rain); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Rain, value); }
				));
				usertypeDefinition.set("weatherChanceSnow", sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Snow); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Snow, value); }
				));
				usertypeDefinition.set("weatherChanceThunder", sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Thunder); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Thunder, value); }
				));

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("sleepCreature", sol::readonly_property([](TES3::Region& self) { return makeLuaObject(self.sleepCreature); }));

				// Expose the current weather, and allow it to be changed via setting.
				usertypeDefinition.set("weather", sol::property(
					[](TES3::Region& self) -> sol::object
				{
					if (self.currentWeatherIndex < TES3::WeatherType::First || self.currentWeatherIndex > TES3::WeatherType::Last) {
						return sol::nil;
					}
					return makeLuaObject(TES3::WorldController::get()->weatherController->arrayWeathers[self.currentWeatherIndex]);
				},
					[](TES3::Region& self, sol::object weather)
				{
					// Get the index, either from a weather object or directly as a number.
					int index = -1;
					if (weather.is<TES3::Weather>()) {
						index = weather.as<TES3::Weather*>()->index;
					}
					else if (weather.is<int>()) {
						index = weather.as<int>();
					}

					// If it was a valid and different index, change the weather to it.
					if (index != self.currentWeatherIndex && index >= TES3::WeatherType::First && index <= TES3::WeatherType::Last) {
						self.changeWeather(index);
					}
				}
				));

				// Basic function binding.
				usertypeDefinition.set("changeWeather", &TES3::Region::changeWeather);
				usertypeDefinition.set("randomizeWeather", &TES3::Region::randomizeWeather);

				// Finish up our usertype.
				state.set_usertype("tes3region", usertypeDefinition);
			}
		}
	}
}

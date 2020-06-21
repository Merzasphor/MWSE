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
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::RegionSound
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::RegionSound>("tes3regionSound");
				usertypeDefinition["new"] = sol::no_constructor;

				// Access to other objects that need to be packaged.
				usertypeDefinition["sound"] =  [](TES3::RegionSound& self) { return self.sound; };

				// Restrict chance [0-100].
				usertypeDefinition["chance"] = sol::property(
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
				);
			}

			// Binding for TES3::Region.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Region>("tes3region");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::BaseObject>();
				setUserdataForTES3BaseObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["name"] = sol::property([](TES3::Region& self) { return self.name; });
				usertypeDefinition["sounds"] = sol::readonly_property(&TES3::Region::sounds);

				// Indirect bindings to unions and arrays.
				usertypeDefinition["weatherChances"] = sol::readonly_property([](TES3::Region& self) { return std::ref(self.weatherChances); });

				// User-friendly access to weather chances.
				usertypeDefinition["weatherChanceAsh"] = sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Ash); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Ash, value); }
				);
				usertypeDefinition["weatherChanceBlight"] = sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Blight); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Blight, value); }
				);
				usertypeDefinition["weatherChanceBlizzard"] = sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Blizzard); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Blizzard, value); }
				);
				usertypeDefinition["weatherChanceClear"] = sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Clear); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Clear, value); }
				);
				usertypeDefinition["weatherChanceCloudy"] = sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Cloudy); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Cloudy, value); }
				);
				usertypeDefinition["weatherChanceFoggy"] = sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Foggy); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Foggy, value); }
				);
				usertypeDefinition["weatherChanceOvercast"] = sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Overcast); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Overcast, value); }
				);
				usertypeDefinition["weatherChanceRain"] = sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Rain); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Rain, value); }
				);
				usertypeDefinition["weatherChanceSnow"] = sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Snow); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Snow, value); }
				);
				usertypeDefinition["weatherChanceThunder"] = sol::property(
					[](TES3::Region& self) { return self.getWeatherChance(TES3::WeatherType::Thunder); },
					[](TES3::Region& self, unsigned char value) { self.setWeatherChance(TES3::WeatherType::Thunder, value); }
				);

				// Access to other objects that need to be packaged.
				usertypeDefinition["sleepCreature"] = sol::readonly_property([](TES3::Region& self) { return self.sleepCreature; });

				// Expose the current weather, and allow it to be changed via setting.
				usertypeDefinition["weather"] = sol::property(
					[](TES3::Region& self) -> TES3::Weather*
				{
					if (self.currentWeatherIndex < TES3::WeatherType::First || self.currentWeatherIndex > TES3::WeatherType::Last) {
						return nullptr;
					}
					return TES3::WorldController::get()->weatherController->arrayWeathers[self.currentWeatherIndex];
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
				);

				// Basic function binding.
				usertypeDefinition["changeWeather"] = &TES3::Region::changeWeather;
				usertypeDefinition["randomizeWeather"] = &TES3::Region::randomizeWeather;
			}
		}
	}
}

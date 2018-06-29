#include "TES3Region.h"

#include "TES3WeatherController.h"

#define TES3_Region_changeWeather 0x4812F0
#define TES3_Region_randomizeWeather 0x4812A0

namespace TES3 {
	void Region::changeWeather(int weather) {
		reinterpret_cast<void(__thiscall *)(Region*,int)>(TES3_Region_changeWeather)(this, weather);
	}

	void Region::randomizeWeather() {
		reinterpret_cast<void(__thiscall *)(Region*)>(TES3_Region_randomizeWeather)(this);
	}

	unsigned char Region::getWeatherChance(unsigned int weatherIndex) {
		if (weatherIndex < WeatherType::First || weatherIndex > WeatherType::Last) {
			return -1;
		}

		return weatherChances[weatherIndex];
	}

	void Region::setWeatherChance(unsigned int weatherIndex, unsigned char chance) {
		// Clamp chance [0-100].
		if (chance < 0) {
			chance = 0;
		}
		else if (chance > 100) {
			chance = 100;
		}

		if (weatherIndex < WeatherType::First || weatherIndex > WeatherType::Last) {
			return;
		}

		weatherChances[weatherIndex] = chance;
	}
}

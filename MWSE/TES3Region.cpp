#include "TES3Region.h"

#define TES3_Region_changeWeather 0x4812F0
#define TES3_Region_randomizeWeather 0x4812A0

namespace TES3 {
	void Region::changeWeather(int weather) {
		reinterpret_cast<void(__thiscall *)(Region*,int)>(TES3_Region_changeWeather)(this, weather);
	}

	void Region::randomizeWeather() {
		reinterpret_cast<void(__thiscall *)(Region*)>(TES3_Region_randomizeWeather)(this);
	}
}

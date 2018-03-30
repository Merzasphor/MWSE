#include "TES3Region.h"

#define TES3_Region_changeWeather 0x4812F0

namespace TES3 {
	void Region::changeWeather(int weather) {
		reinterpret_cast<void(__thiscall *)(Region*,int)>(TES3_Region_changeWeather)(this, weather);
	}
}

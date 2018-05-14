#pragma once

#include "TES3Object.h"
#include "TES3Vectors.h"

namespace TES3 {
	struct WeatherController {
		int sceneWeather; // 0x0
		int unknown_0x4;
		int unknown_0x8;
		int daysRemaining; // 0xC
		char unknown_0x10;
		Weather * arrayWeathers[10]; // 0x14
		Weather * currentWeather; // 0x3C
		Weather * nextWeather; // 0x40
		Moon * moonSecunda; // 0x44
		Moon * moonMasser; // 0x48
		void * unknown_0x4C;
		int unknown_0x50;
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C;
		int unknown_0x60;
		int unknown_0x64;
		int unknown_0x68;
		int unknown_0x6C;
		int unknown_0x70;
		int unknown_0x74;
		int unknown_0x78;
		int unknown_0x7C;
		int unknown_0x80;
		int unknown_0x84;
		int unknown_0x88;
		int unknown_0x8C;
		Vector3 currentSkyColor; // 0x90
		Vector3 currentFogColor; // 0x9C
		int unknown_0xA8;
		int unknown_0xAC;
		int unknown_0xB0;
		int unknown_0xB4;
		Vector3 windDirection; // 0xB8
		int unknown_0xC4;
		int unknown_0xC8;
		int unknown_0xCC;
		int unknown_0xD0;
		int sunglareFaderMax; // 0xD4
		int sunglareFaderAngleMax; // 0xD8
		float sunriseHour; // 0xDC
		float sunsetHour; // 0xE0
		float sunriseDuration; // 0xE4
		float sunsetDuration; // 0xE8
		int unknown_0xEC;
		int unknown_0xF0;
		int unknown_0xF4;
		int unknown_0xF8;
		float unknown_0xFC;
		int unknown_0x100;
		int unknown_0x104;
		int unknown_0x108;
		int unknown_0x10C;
		int unknown_0x110;
		int unknown_0x114;
		int unknown_0x118;
		int unknown_0x11C;
		int unknown_0x120;
		int unknown_0x124;
		int unknown_0x128;
		int unknown_0x12C;
		int unknown_0x130;
		int unknown_0x134;
		int unknown_0x138;
		int unknown_0x13C;
		int unknown_0x140;
		int unknown_0x144;
		int unknown_0x148;
		int unknown_0x14C;
		int unknown_0x150;
		int unknown_0x154;
		int unknown_0x158;
		int unknown_0x15C;
		int unknown_0x160;
		int unknown_0x164;
		int unknown_0x168;
		int hoursBetweenWeatherChanges; // 0x16C
		float transitionScalar; // 0x170
		float hoursRemaining; // 0x174
		int unknown_0x178;
		int unknown_0x17C;
		int unknown_0x180;
		int unknown_0x184;
		int unknown_0x188;
		float unknown_0x18C;
		float unknown_0x190;
		float unknown_0x194;
		char unknown_0x198;
		char unknown_0x199;
		int timescaleClouds; // 0x19C
		int underwaterSunriseFog; // 0x1A0
		int underwaterDayFog; // 0x1A4
		int underwaterSunsetFog; // 0x1A8
		int underwaterNightFog; // 0x1AC
		int underwaterIndoorFog; // 0x1B0
		Vector3 underwaterCol; // 0x1B4
		int underwaterColWeight; // 0x1C0
		Vector3 sunglareFaderCol; // 0x1C4
		int unknown_0x1D0;
		int unknown_0x1D4;
		int soundUnderwater; // 0x1D8
		int unknown_0x1DC;
		int unknown_0x1E0;
		int unknown_0x1E4;
		int unknown_0x1E8;
		int unknown_0x1EC;
	};
	static_assert(sizeof(WeatherController) == 0x1F0, "TES3::WeatherController failed size validation");
}

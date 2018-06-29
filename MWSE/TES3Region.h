#pragma once

#include "TES3Defines.h"

#include "TES3Object.h"

namespace TES3 {
	struct RegionSound {
		Sound * sound; // 0x0
		unsigned char chance; // 0x4
	};
	static_assert(sizeof(RegionSound) == 0x8, "TES3::RegionSound failed size validation");

	struct Region : BaseObject {
		char id[32]; // 0x10
		char name[32]; // 0x30
		unsigned char weatherChances[10];
		unsigned char padding_0x5A[2];
		Actor * sleepCreature; // 0x5C
		Iterator<RegionSound> sounds; // 0x60
		int currentWeatherIndex; // 0x74

		//
		// Other related this-call functions.
		//

		void changeWeather(int);
		void randomizeWeather();

		//
		// Custom functions.
		//

		unsigned char getWeatherChance(unsigned int);
		void setWeatherChance(unsigned int, unsigned char);

	};
	static_assert(sizeof(Region) == 0x78, "TES3::Region failed size validation");
}

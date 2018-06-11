#pragma once

#include "TES3Defines.h"

#include "TES3Object.h"

namespace TES3 {
	struct Region : BaseObject {
		char id[32]; // 0x10
		char name[32]; // 0x30
		unsigned char weatherChanceClear; // 0x50
		unsigned char weatherChanceCloudy; // 0x51
		unsigned char weatherChanceFoggy; // 0x52
		unsigned char weatherChanceOvercast; // 0x53
		unsigned char weatherChanceRain; // 0x54
		unsigned char weatherChanceThunder; // 0x55
		unsigned char weatherChanceAsh; // 0x56
		unsigned char weatherChanceBlight; // 0x57
		unsigned char weatherChanceSnow; // 0x58
		unsigned char weatherChanceBlizzard; // 0x59
		unsigned char unknown_0x5A;
		unsigned char unknown_0x5B;
		Actor * sleepCreature; // 0x5C
		int unknown_0x60[5]; // Unknown2 in Master?
		int currentWeatherIndex; // 0x74

		//
		// Other related this-call functions.
		//

		void changeWeather(int);
		void randomizeWeather();

	};
	static_assert(sizeof(Region) == 0x78, "TES3::Region failed size validation");
}

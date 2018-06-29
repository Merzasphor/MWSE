#pragma once

#include "TES3Defines.h"

#include "TES3Vectors.h"

namespace TES3 {
	struct Weather {
		void * vTable; // 0x0
		int index; // 0x4
		float transitionDelta; // 0x8
		float glareView; // 0xC
		WeatherController * weatherController; // 0x10
		Vector3 ambientSunriseCol; // 0x14
		Vector3 ambientDayCol; // 0x20
		Vector3 ambientSunsetCol; // 0x2C
		Vector3 ambientNightCol; // 0x38
		Vector3 fogSunriseCol; // 0x44
		Vector3 fogDayCol; // 0x50
		Vector3 fogSunsetCol; // 0x5C
		Vector3 fogNightCol; // 0x68
		Vector3 skySunriseCol; // 0x74
		Vector3 skyDayCol; // 0x80
		Vector3 skySunsetCol; // 0x8C
		Vector3 skyNightCol; // 0x98
		Vector3 sunSunriseCol; // 0xA4
		Vector3 sunDayCol; // 0xB0
		Vector3 sunSunsetCol; // 0xBC
		Vector3 sunNightCol; // 0xC8
		Vector3 sundiscSunsetCol; // 0xD4
		int unknown_0xE0;
		int unknown_0xE4;
		int unknown_0xE8;
		int unknown_0xEC;
		float cloudsMaxPercent; // 0xF0
		float landFogDayDepth; // 0xF4
		float landFogNightDepth; // 0xF8
		float cloudsSpeed; // 0xFC
		float windSpeed; // 0x100
		char * texturePathCloud; // 0x104
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
		int unknown_0x16C;
		int unknown_0x170;
		int unknown_0x174;
		int unknown_0x178;
		int unknown_0x17C;
		int unknown_0x180;
		int unknown_0x184;
		int unknown_0x188;
		int unknown_0x18C;
		int unknown_0x190;
		int unknown_0x194;
		char unknown_0x198;
		bool flagUnderwaterSoundActive; // 0x199
		int unknown_0x19C;
		int unknown_0x1A0;
		int unknown_0x1A4;
		int unknown_0x1A8;
		int unknown_0x1AC;
		int unknown_0x1B0;
		int unknown_0x1B4;
		int unknown_0x1B8;
		int unknown_0x1BC;
		int unknown_0x1C0;
		int unknown_0x1C4;
		int unknown_0x1C8;
		int unknown_0x1CC;
		int unknown_0x1D0;
		int unknown_0x1D4;
		int unknown_0x1D8;
		int unknown_0x1DC;
		int unknown_0x1E0;
		int unknown_0x1E4;
		int unknown_0x1E8;
		int unknown_0x1EC;
		int unknown_0x1F0;
		int unknown_0x1F4;
		int unknown_0x1F8;
		int unknown_0x1FC;
		int unknown_0x200;
		int unknown_0x204;
		int unknown_0x208;
		char unknown_0x20C;
		char unknown_0x20D;
		bool soundIDAmbientLoop; // 0x20E
		int unknown_0x210;
		int unknown_0x214;
		int unknown_0x218;
		int unknown_0x21C;
		int unknown_0x220;
		int unknown_0x224;
		int unknown_0x228;
		int unknown_0x22C;
		int unknown_0x230;
		int unknown_0x234;
		int unknown_0x238;
		int unknown_0x23C;
		int unknown_0x240;
		int unknown_0x244;
		int unknown_0x248;
		int unknown_0x24C;
		int unknown_0x250;
		int unknown_0x254;
		int unknown_0x258;
		int unknown_0x25C;
		int unknown_0x260;
		int unknown_0x264;
		int unknown_0x268;
		int unknown_0x26C;
		int unknown_0x270;
		int unknown_0x274;
		int unknown_0x278;
		int unknown_0x27C;
		int unknown_0x280;
		int unknown_0x284;
		int unknown_0x288;
		int unknown_0x28C;
		int unknown_0x290;
		int unknown_0x294;
		int unknown_0x298;
		int unknown_0x29C;
		int unknown_0x2A0;
		int unknown_0x2A4;
		int unknown_0x2A8;
		int unknown_0x2AC;
		int unknown_0x2B0;
		int unknown_0x2B4;
		int unknown_0x2B8;
		int unknown_0x2BC;
		int unknown_0x2C0;
		int unknown_0x2C4;
		int unknown_0x2C8;
		int unknown_0x2CC;
		int unknown_0x2D0;
		int unknown_0x2D4;
		int unknown_0x2D8;
		int unknown_0x2DC;
		int unknown_0x2E0;
		int unknown_0x2E4;
		int unknown_0x2E8;
		int unknown_0x2EC;
		int unknown_0x2F0;
		int unknown_0x2F4;
		int unknown_0x2F8;
		int unknown_0x2FC;
		int unknown_0x300;
		int unknown_0x304;
		int unknown_0x308;
		int unknown_0x30C;
		int unknown_0x310;
		int unknown_0x314;
	};
	static_assert(sizeof(Weather) == 0x318, "TES3::Weather failed size validation");
}

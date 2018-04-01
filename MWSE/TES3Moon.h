#pragma once

#include "TES3Object.h"

namespace TES3 {
	struct Moon {
		int unknown_0x0;
		int unknown_0x4;
		int unknown_0x8;
		int unknown_0xC;
		int unknown_0x10;
		WeatherController * weatherController; // 0x14
		int unknown_0x18;
		int unknown_0x1C;
		int unknown_0x20;
		int unknown_0x24;
		char * texture; // 0x28
		int unknown_0x2C;
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		char unknown_0x48;
		char unknown_0x49;
		unsigned char moonIsRed; // 0x4A
		char unknown_0x4B;
		int phase; // 0x4C
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
		int unknown_0x90;
		int unknown_0x94;
		int unknown_0x98;
		int unknown_0x9C;
		int unknown_0xA0;
		int unknown_0xA4;
		int unknown_0xA8;
		int unknown_0xAC;
		int unknown_0xB0;
		int unknown_0xB4;
		int unknown_0xB8;
		int unknown_0xBC;
		int unknown_0xC0;
		int unknown_0xC4;
		int unknown_0xC8;
		int unknown_0xCC;
		int unknown_0xD0;
		int unknown_0xD4;
		int unknown_0xD8;
		int unknown_0xDC;
		int unknown_0xE0;
		int unknown_0xE4;
		int unknown_0xE8;
		int unknown_0xEC;
		int unknown_0xF0;
		int unknown_0xF4;
		int unknown_0xF8;
		int unknown_0xFC;
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
	};
	static_assert(sizeof(Moon) == 0x15C, "TES3::Moon failed size validation");
}

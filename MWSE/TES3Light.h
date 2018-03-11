#pragma once

#include "TES3Object.h"

namespace TES3 {
	struct Light : PhysicalObject {
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		char* name; // 0x48
		int unknown_0x4C;
		char* model; // 0x50
		char* icon; // 0x54
		float weight; // 0x58
		long value; // 0x5C
		int unknown_0x60;
		int unknown_0x64;
		int unknown_0x68;
		int unknown_0x6C;
		int unknown_0x70;
	};
	static_assert(sizeof(Light) == 0x74, "TES3::Light failed size validation");
}

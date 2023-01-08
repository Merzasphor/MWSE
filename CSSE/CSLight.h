#pragma once

#include "CSAnimatedObject.h"

namespace se::cs {
	struct Light : AnimatedObject {
		char* name; // 0x4C
		Script* script; // 0x50
		char* model; // 0x54
		char* icon; // 0x58
		float weight; // 0x60
		int value; // 0x64
		int time; // 0x68
		int radius; // 0x6C
		byte color[4]; // 0x70
		unsigned int flags; // 0x74
		Sound* sound; // 0x78

		void updateLightingData(NI::Light* light, Cell* cell, bool flag = false);
	};
	static_assert(sizeof(Light) == 0x78, "Light failed size validation");
}

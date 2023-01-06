#pragma once

#include "CSPhysicalObject.h"

namespace se::cs {
	struct Apparatus : PhysicalObject {
		char model[32]; // 0x48
		char name[32]; // 0x68
		Script* script; // 0x88
		char icon[32]; // 0x8C
		int type; // 0xAC
		float quality; // 0xB0
		float weight; // 0xB4
		int value; // 0xB8
	};
	static_assert(sizeof(Apparatus) == 0xBC, "Apparatus failed size validation");
}

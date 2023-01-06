#pragma once

#include "CSPhysicalObject.h"

namespace se::cs {
	struct Probe : PhysicalObject {
		char name[32]; // 0x48
		Script* script; // 0x68
		char model[32]; // 0x6C
		char icon[32]; // 0x8C
		float weight; // 0xAC
		int value; // 0xB0
		float quality; // 0xB4
		int uses; // 0xB8
	};
	static_assert(sizeof(Probe) == 0xBC, "Probe failed size validation");
}

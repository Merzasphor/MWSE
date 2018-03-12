#pragma once

#include "TES3Object.h"

namespace TES3 {
	struct Class : BaseObject {
		char id[32];
		char name[32];
		int attributes[2];
		int specialization;
		int skills[10];
		int playable;
		int services;
		int field_8C;
		int field_90;
	};
	static_assert(sizeof(Class) == 0x94, "TES3::Class failed size validation");
}

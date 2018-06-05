#pragma once

#include "TES3Defines.h"

#include "TES3Object.h"

#include "sol_forward.hpp"

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

		//
		// Virtual table overrides.
		//

		char* getName();

		//
		// Lua-specific interfaces.
		//

		sol::table getAttributes();
		sol::table getMajorSkills();
		sol::table getMinorSkills();

	};
	static_assert(sizeof(Class) == 0x94, "TES3::Class failed size validation");
}

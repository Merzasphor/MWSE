#pragma once

#include "NIDynamicEffect.h"
#include "NIColor.h"

namespace NI {
	struct Light : DynamicEffect {
		float dimmer; // 0xA8
		Color ambient; // 0xAC
		Color diffuse; // 0xB8
		Color specular; // 0xC4

		//
		// Other related this-call functions.
		//

		Light * ctor();

	};
	static_assert(sizeof(Light) == 0xD0, "NI::Light failed size validation");
}

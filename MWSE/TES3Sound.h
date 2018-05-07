#pragma once

#include "TES3Object.h"

namespace TES3 {
	struct Sound : BaseObject {
		char field_10;
		char id[32]; // 0x11
		char filename[32]; // 0x31
		char unknown_0x51;
		char unknown_0x52;
		char unknown_0x53;
		int unknown_0x54;

		//
		// Other related this-call functions.
		//

		bool play(TES3::Reference* reference, unsigned char volume = 0xFD, float pitch = 1.0f, int is3D = 0);

	};
	static_assert(sizeof(Sound) == 0x58, "TES3::Sound failed size validation");
}

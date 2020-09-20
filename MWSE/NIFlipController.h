#pragma once

#include "NITimeController.h"
#include "NITexture.h"

namespace NI {
	struct FlipController : TimeController {
		TArray<Pointer<Texture>> textures; // 0x34
		unsigned int currentIndex; // 0x4C
		unsigned int affectedMap; // 0x50
		float flipStartTime; // 0x54
		float duration; // 0x58
		float secondsPerFrame; // 0x5C

		//
		// Custom functions.
		//

		void copy(FlipController* to) const;

	};
	static_assert(sizeof(FlipController) == 0x60, "NI::FlipController failed size validation");
}

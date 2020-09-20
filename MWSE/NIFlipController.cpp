#include "NIFlipController.h"

namespace NI {
	void FlipController::copy(FlipController* to) const {
		TimeController::_copy(this, to);

		// Copy fields.
		to->textures = textures;
		to->currentIndex = currentIndex;
		to->affectedMap = affectedMap;
		to->flipStartTime = flipStartTime;
		to->duration = duration;
		to->secondsPerFrame = secondsPerFrame;
	}
}

#include "TES3PlayerAnimationData.h"

namespace TES3 {
	bool PlayerAnimationData::force1stPerson() {
		if (is3rdPerson) {
			togglePOV = true;
		}
		return togglePOV;
	}

	bool PlayerAnimationData::force3rdPerson() {
		if (!is3rdPerson) {
			togglePOV = true;
		}
		return togglePOV;
	}
}

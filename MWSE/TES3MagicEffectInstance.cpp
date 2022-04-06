#include "TES3MagicEffectInstance.h"

namespace TES3 {
	int MagicEffectInstance::getEffectiveMagnitude() const {
		return magnitude * (1.0f - resistedPercent / 100.0f);
	}
}

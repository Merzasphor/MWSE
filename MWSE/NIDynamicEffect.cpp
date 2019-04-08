#include "NIDynamicEffect.h"

namespace NI {
	int DynamicEffect::getType() {
		return vTable.asDynamicEffect->getType(this);
	}
}

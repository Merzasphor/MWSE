#include "MathUtil.h"

namespace se::math {
	void standardizeAngleRadians(float& value) {
		while (value > M_2PIf) {
			value -= M_2PIf;
		}
		while (value < 0.0f) {
			value += M_2PIf;
		}
	}
}

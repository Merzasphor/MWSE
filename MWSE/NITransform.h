#pragma once

#include "NIDefines.h"
#include "TES3Vectors.h"

namespace NI {
	struct Transform {
		TES3::Matrix33 rotation;
		TES3::Vector3 translation;
		float scale;
	};
	static_assert(sizeof(Transform) == 0x34, "NI::Transform failed size validation");
}

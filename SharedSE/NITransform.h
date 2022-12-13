#pragma once

#include "NIMatrix33.h"

namespace NI {
	struct Transform {
		Matrix33 rotation;
		Vector3 translation;
		float scale;
	};
	static_assert(sizeof(Transform) == 0x34, "NI::Transform failed size validation");
}

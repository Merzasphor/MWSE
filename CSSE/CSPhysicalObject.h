#pragma once

#include "CSObject.h"

#include "NIVector3.h"

namespace se::cs {
	struct PhysicalObject : Object {
		NI::Vector3 boundingBoxMin;
		NI::Vector3 boundingBoxMax;
		int unknown_0x40;
		const char* objectID; // 0x44

		bool canRotateOnAllAxes() const;
	};
	static_assert(sizeof(PhysicalObject) == 0x48, "TES3::PhysicalObject failed size validation");
}

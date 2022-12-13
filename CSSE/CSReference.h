#pragma once

#include "CSPhysicalObject.h"

namespace se::cs {
	struct Reference : Object {
		BaseObject* baseObject; // 0x28
		NI::Vector3 orientationNonAttached; //0x2C
		NI::Vector3 anotherOrientation; //0x38
		NI::Vector3 yetAnotherOrientation; //0x44
		NI::Vector3 position; // 0x50
	};
}

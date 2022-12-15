#pragma once

#include "CSPhysicalObject.h"

namespace se::cs {
	struct Reference : Object {
		struct ReferenceData {
			BaseObject* baseObject; // 0x0
			NI::Vector3 orientationNonAttached; // 0x4
			NI::Vector3 unknown_0x10; // Position-related.
			NI::Vector3 yetAnotherOrientation; // 0x1C
			NI::Vector3 position; // 0x28
			NI::Vector3 undoPosition; // 0x34
		};
		union {
			ReferenceData referenceData; // 0x28
			struct {
				BaseObject* baseObject; // 0x28
				NI::Vector3 orientationNonAttached; //0x2C
				NI::Vector3 unknown_0x10; // 0x38
				NI::Vector3 yetAnotherOrientation; // 0x44
				NI::Vector3 position; // 0x50
				NI::Vector3 undoPosition; // 0x5C
			};
		};
		int unknown_0x68;
		int unknown_0x6C;
		int unknown_0x70;
		int unknown_0x74;
	};
	static_assert(sizeof(Reference) == 0x78, "TES3::Reference failed size validation");
}

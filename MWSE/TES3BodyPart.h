#pragma once

#include "TES3Defines.h"

#include "TES3Object.h"

namespace TES3 {
	struct BodyPart : PhysicalObject {
		char * unknown_0x30;
		char * fileName; // 0x34
		signed char part; // 0x38
		bool vampiric; // 0x39
		unsigned char flags; // 0x3A
		signed char partType; // 0x3B
		NI::Node * mirroredNode; // 0x3C // Type: BSMirroredNode.
	};
	static_assert(sizeof(BodyPart) == 0x40, "TES3::BodyPart failed size validation");
}

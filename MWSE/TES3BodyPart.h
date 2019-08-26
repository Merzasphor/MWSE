#pragma once

#include "TES3Defines.h"

#include "TES3Object.h"

#include "NIPointer.h"

namespace TES3 {
	namespace BodyPartFlag {
		enum Flag : unsigned int {
			Female = 0x1,
			Playable = 0x2
		};

	}

	struct BodyPart : PhysicalObject {
		char * fileName; // 0x30
		char * raceName; // 0x34
		signed char part; // 0x38
		bool vampiric; // 0x39
		mwse::bitset8 flags; // 0x3A
		signed char partType; // 0x3B
		NI::Pointer<NI::Node> mirroredNode; // 0x3C // Type: BSMirroredNode.

		//
		// Custom functions.
		//

		bool getFlag(BodyPartFlag::Flag flag);
		void setFlag(BodyPartFlag::Flag flag, bool set);

	};
	static_assert(sizeof(BodyPart) == 0x40, "TES3::BodyPart failed size validation");
}

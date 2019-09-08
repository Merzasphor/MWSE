#pragma once

#include "NINode.h"

#include "BitUtil.h"

namespace NI {
	struct CollisionSwitch : Node {
		static const unsigned short flagCollision = 0x20;

		CollisionSwitch() {
			vTable.asNode = reinterpret_cast<NI::Node_vTable*>(0x74F418);
			BITMASK_SET_ON(flags, flagCollision);
		}

		bool getCollisionActive() {
			return BITMASK_TEST(flags, flagCollision);
		}

		void setCollisionActive(bool active) {
			BITMASK_SET(flags, flagCollision, active);
		}
	};
	static_assert(sizeof(CollisionSwitch) == 0xB0, "NI::CollisionSwitch failed size validation");
}
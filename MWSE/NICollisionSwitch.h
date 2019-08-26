#pragma once

#include "NINode.h"

namespace NI {
	struct CollisionSwitch : Node {
		static const unsigned short flagCollision = 0x20;
		static const size_t flagCollisionBit = 5;

		CollisionSwitch() {
			vTable.asNode = reinterpret_cast<NI::Node_vTable*>(0x74F418);
			flags.set(flagCollisionBit, true);
		}

		bool getCollisionActive() {
			return flags.test(flagCollisionBit);
		}

		void setCollisionActive(bool active) {
			flags.set(flagCollisionBit, active);
		}
	};
	static_assert(sizeof(CollisionSwitch) == 0xB0, "NI::CollisionSwitch failed size validation");
}
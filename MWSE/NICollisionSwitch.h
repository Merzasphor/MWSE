#pragma once

#include "NINode.h"

namespace NI {
	struct CollisionSwitch : Node {
		static const unsigned short flagCollision = 0x20;

		CollisionSwitch() {
			vTable.asNode = reinterpret_cast<NI::Node_vTable*>(0x74F418);
			flags |= flagCollision;
		}

		bool getCollisionActive() {
			return (flags & flagCollision) != 0;
		}

		void setCollisionActive(bool active) {
			if (active) {
				flags |= flagCollision;
			}
			else {
				flags &= ~flagCollision;
			}
		}
	};
	static_assert(sizeof(CollisionSwitch) == 0xB0, "NI::CollisionSwitch failed size validation");
}
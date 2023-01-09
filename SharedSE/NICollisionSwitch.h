#pragma once

#include "NINode.h"

namespace NI {
	struct CollisionSwitch : Node {
		static constexpr unsigned short flagCollision = 0x20;

		bool getCollisionActive() const;
	};
	static_assert(sizeof(CollisionSwitch) == 0xB0, "NI::CollisionSwitch failed size validation");
}
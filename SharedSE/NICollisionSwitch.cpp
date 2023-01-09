#include "NICollisionSwitch.h"

namespace NI {
	bool CollisionSwitch::getCollisionActive() const {
		return (flags & flagCollision) == flagCollision;
	}
}

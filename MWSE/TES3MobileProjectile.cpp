#include "TES3MobileProjectile.h"

namespace TES3 {
	int MobileProjectile::onActorCollision(int something) {
		return vTable->onActorCollision(this, something);
	}
}
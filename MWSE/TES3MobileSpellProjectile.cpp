#include "TES3MobileSpellProjectile.h"

#include "TES3MagicSourceInstance.h"
#include "TES3SpellInstanceController.h"
#include "TES3WorldController.h"

namespace TES3 {
	MagicSourceInstance* MobileSpellProjectile::getInstance() {
		return TES3::WorldController::get()->spellInstanceController->getInstanceFromSerial(spellInstanceSerial);
	}

	void MobileSpellProjectile::explode() {
		auto spellInstance = getInstance();
		if (!spellInstance) {
			return;
		}

		// Create temporary collision data for the projectile hit function.
		MobileObject::Collision collision;
		collision.valid = true;
		collision.time = 0;
		collision.point = position;
		collision.objectPosAtCollision = position;
		collision.colliderRef = nullptr;
		collision.collisionType = MobileObject::Collision::CollisionType::None;

		// Call projectile impact handling function.
		spellInstance->projectileHit(&collision);

		// Expire projectile.
		enterLeaveSimulation(false);
		flagExpire = true;
	}
}

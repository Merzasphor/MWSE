#include "TES3MobileProjectile.h"

#include "LuaManager.h"

#define TES3_MobileProjectile_onActorCollision 0x573860

namespace TES3 {
	char MobileProjectile::onActorCollision(int referenceIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->hitReferences->hit[referenceIndex].reference;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		char result = reinterpret_cast<char(__thiscall *)(MobileProjectile*, int)>(TES3_MobileProjectile_onActorCollision)(this, referenceIndex);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::ProjectileHitEvent(this, hitReference));

		return result;
	}
}
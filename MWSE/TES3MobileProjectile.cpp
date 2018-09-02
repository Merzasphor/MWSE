#include "TES3MobileProjectile.h"

#include "LuaManager.h"

#include "LuaMobileProjectileActorCollisionEvent.h"
#include "LuaMobileObjectCollisionEvent.h"

#define TES3_MobileProjectile_onActorCollision 0x573860
#define TES3_MobileProjectile_onObjectCollision 0x573820
#define TES3_MobileProjectile_onTerrainCollision 0x5737F0
#define TES3_MobileProjectile_onWaterCollision 0x573790

namespace TES3 {
	signed char MobileProjectile::onActorCollision(int hitReferenceIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->hitReferences->hit[hitReferenceIndex].reference;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		signed char result = reinterpret_cast<char(__thiscall *)(MobileObject*, int)>(TES3_MobileProjectile_onActorCollision)(this, hitReferenceIndex);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::MobileProjectileActorCollisionEvent(this, hitReference));

		return result;
	}

	signed char MobileProjectile::onObjectCollision(int hitReferenceIndex, signed char flag) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->hitReferences->hit[hitReferenceIndex].reference;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		signed char result = reinterpret_cast<char(__thiscall *)(MobileObject*, int, signed char)>(TES3_MobileProjectile_onObjectCollision)(this, hitReferenceIndex, flag);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));

		return result;
	}

	signed char MobileProjectile::onTerrainCollision(int hitReferenceIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->hitReferences->hit[hitReferenceIndex].reference;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		signed char result = reinterpret_cast<char(__thiscall *)(MobileObject*, int)>(TES3_MobileProjectile_onTerrainCollision)(this, hitReferenceIndex);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));

		return result;
	}

	signed char MobileProjectile::onWaterCollision(int hitReferenceIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->hitReferences->hit[hitReferenceIndex].reference;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		signed char result = reinterpret_cast<char(__thiscall *)(MobileObject*, int)>(TES3_MobileProjectile_onWaterCollision)(this, hitReferenceIndex);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));

		return result;
	}
}

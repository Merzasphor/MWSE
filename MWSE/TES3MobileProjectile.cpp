#include "TES3MobileProjectile.h"

#include "LuaManager.h"

#include "LuaMobileProjectileActorCollisionEvent.h"
#include "LuaMobileProjectileObjectCollisionEvent.h"
#include "LuaMobileProjectileTerrainCollisionEvent.h"
#include "LuaMobileObjectCollisionEvent.h"

namespace TES3 {
	const auto TES3_MobileProjectile_onActorCollision = reinterpret_cast<bool(__thiscall *)(MobileProjectile*, int)>(0x573860);
	const auto TES3_MobileProjectile_onObjectCollision = reinterpret_cast<bool(__thiscall *)(MobileProjectile*, int, bool)>(0x573820);
	const auto TES3_MobileProjectile_onTerrainCollision = reinterpret_cast<bool(__thiscall *)(MobileProjectile*, int)>(0x5737F0);
	const auto TES3_MobileProjectile_onWaterCollision = reinterpret_cast<bool(__thiscall *)(MobileProjectile*, int)>(0x573790);

	bool MobileProjectile::onActorCollision(int collisionIndex) {
		// Grab the collision data now, it won't be available after calling the main function.
		const auto& hit = this->arrayCollisionResults[collisionIndex];
		TES3::Reference* hitReference = hit.colliderRef;
		TES3::Vector3 point = hit.point;
		TES3::Vector3 pos = hit.objectPosAtCollision;
		TES3::Vector3 vel = hit.velocity;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		bool result = TES3_MobileProjectile_onActorCollision(this, collisionIndex);

		// Fire off our hit event.
		if (mwse::lua::event::MobileProjectileActorCollisionEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileProjectileActorCollisionEvent(this, hitReference, point, pos, vel));
		}

		return result;
	}

	bool MobileProjectile::onObjectCollision(int collisionIndex, bool flag) {
		// Grab the collision data now, it won't be available after calling the main function.
		const auto& hit = this->arrayCollisionResults[collisionIndex];
		TES3::Reference* hitReference = hit.colliderRef;
		TES3::Vector3 point = hit.point;
		TES3::Vector3 pos = hit.objectPosAtCollision;
		TES3::Vector3 vel = hit.velocity;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		bool result = TES3_MobileProjectile_onObjectCollision(this, collisionIndex, flag);

		// Fire off our hit event.
		if (mwse::lua::event::MobileProjectileObjectCollisionEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileProjectileObjectCollisionEvent(this, hitReference, point, pos, vel));
		}

		return result;
	}

	bool MobileProjectile::onTerrainCollision(int collisionIndex) {
		// Grab the collision data now, it won't be available after calling the main function.
		const auto& hit = this->arrayCollisionResults[collisionIndex];
		TES3::Vector3 point = hit.point;
		TES3::Vector3 pos = hit.objectPosAtCollision;
		TES3::Vector3 vel = hit.velocity;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		bool result = TES3_MobileProjectile_onTerrainCollision(this, collisionIndex);

		// Fire off our hit event.
		if (mwse::lua::event::MobileProjectileTerrainCollisionEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileProjectileTerrainCollisionEvent(this, point, pos, vel));
		}
		return result;
	}

	bool MobileProjectile::onWaterCollision(int collisionIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->arrayCollisionResults[collisionIndex].colliderRef;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		bool result = TES3_MobileProjectile_onWaterCollision(this, collisionIndex);

		// Fire off our hit event.
		if (mwse::lua::event::MobileObjectCollisionEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));
		}

		return result;
	}

}

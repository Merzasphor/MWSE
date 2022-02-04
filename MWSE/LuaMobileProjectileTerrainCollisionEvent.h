#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Vectors.h"

namespace mwse::lua::event {
	class MobileProjectileTerrainCollisionEvent : public ObjectFilteredEvent, public DisableableEvent<MobileProjectileTerrainCollisionEvent> {
	public:
		MobileProjectileTerrainCollisionEvent(TES3::MobileProjectile* projectile, TES3::Vector3& point, TES3::Vector3& pos, TES3::Vector3& vel);
		sol::table createEventTable();

	protected:
		TES3::MobileProjectile* m_Projectile;
		TES3::Vector3 m_CollisionPoint;
		TES3::Vector3 m_Position;
		TES3::Vector3 m_Velocity;
	};
}
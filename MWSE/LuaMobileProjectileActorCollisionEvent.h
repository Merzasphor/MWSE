#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class MobileProjectileActorCollisionEvent : public ObjectFilteredEvent {
			public:
				MobileProjectileActorCollisionEvent(TES3::MobileProjectile* projectile, TES3::Reference* targetReference);
				sol::table createEventTable();

			protected:
				TES3::MobileProjectile* m_Projectile;
				TES3::Reference* m_TargetReference;
			};
		}
	}
}

#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class ProjectileExpireEvent : public ObjectFilteredEvent {
			public:
				ProjectileExpireEvent(TES3::MobileProjectile* projectile);
				sol::table createEventTable();

			protected:
				TES3::MobileProjectile* m_Projectile;
			};
		}
	}
}

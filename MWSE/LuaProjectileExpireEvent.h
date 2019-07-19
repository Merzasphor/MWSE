#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class ProjectileExpireEvent : public ObjectFilteredEvent, public DisableableEvent<ProjectileExpireEvent> {
			public:
				ProjectileExpireEvent(TES3::MobileProjectile* projectile);
				sol::table createEventTable();

			protected:
				TES3::MobileProjectile* m_Projectile;
			};
		}
	}
}

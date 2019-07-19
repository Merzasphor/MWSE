#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class DamagedEvent : public ObjectFilteredEvent, public DisableableEvent<DamagedEvent> {
			public:
				DamagedEvent(TES3::MobileActor* mobileActor, float damage);
				sol::table createEventTable();

			protected:
				TES3::MobileActor * m_MobileActor;
				float m_Damage;
			};
		}
	}
}

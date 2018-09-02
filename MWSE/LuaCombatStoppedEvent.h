#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CombatStoppedEvent : public ObjectFilteredEvent {
			public:
				CombatStoppedEvent(TES3::MobileActor* mobileActor);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_MobileActor;
			};
		}
	}
}

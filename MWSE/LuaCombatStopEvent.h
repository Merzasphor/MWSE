#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CombatStopEvent : public ObjectFilteredEvent {
			public:
				CombatStopEvent(TES3::MobileActor* mobileActor);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_MobileActor;
			};
		}
	}
}

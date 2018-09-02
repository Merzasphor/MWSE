#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CombatStartEvent : public ObjectFilteredEvent {
			public:
				CombatStartEvent(TES3::MobileActor* mobileActor, TES3::MobileActor* target);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_MobileActor;
				TES3::MobileActor* m_Target;
			};
		}
	}
}

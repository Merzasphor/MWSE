#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class DeathEvent : public ObjectFilteredEvent {
			public:
				DeathEvent(TES3::MobileActor* mobileActor);
				sol::table createEventTable();

			protected:
				TES3::MobileActor * m_MobileActor;
			};
		}
	}
}

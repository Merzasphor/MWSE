#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class DetermineActionEvent : public ObjectFilteredEvent {
			public:
				DetermineActionEvent(TES3::CombatSession * session);
				sol::table createEventTable();

			protected:
				TES3::CombatSession* m_Session;
			};
		}
	}
}

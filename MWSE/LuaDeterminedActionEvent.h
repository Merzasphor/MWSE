#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class DeterminedActionEvent : public ObjectFilteredEvent, public DisableableEvent<DeterminedActionEvent> {
			public:
				DeterminedActionEvent(TES3::CombatSession * session);
				sol::table createEventTable();

			protected:
				TES3::CombatSession* m_Session;
			};
		}
	}
}

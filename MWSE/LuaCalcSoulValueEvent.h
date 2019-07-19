#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CalculateSoulValueEvent : public ObjectFilteredEvent, public DisableableEvent<CalculateSoulValueEvent> {
			public:
				CalculateSoulValueEvent(TES3::Actor * actor, int value);
				sol::table createEventTable();

			protected:
				TES3::Actor* m_Actor;
				int m_Value;
			};
		}
	}
}

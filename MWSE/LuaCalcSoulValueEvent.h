#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CalculateSoulValueEvent : public ObjectFilteredEvent {
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

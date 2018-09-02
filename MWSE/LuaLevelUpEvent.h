#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class LevelUpEvent : public GenericEvent {
			public:
				LevelUpEvent();
				sol::table createEventTable();
				sol::object getEventOptions();
			};
		}
	}
}

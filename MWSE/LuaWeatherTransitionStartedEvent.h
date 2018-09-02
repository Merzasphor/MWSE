#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class WeatherTransitionStartedEvent : public GenericEvent {
			public:
				WeatherTransitionStartedEvent();
				sol::table createEventTable();
			};
		}
	}
}

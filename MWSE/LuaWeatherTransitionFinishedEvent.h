#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class WeatherTransitionFinishedEvent : public GenericEvent {
			public:
				WeatherTransitionFinishedEvent();
				sol::table createEventTable();
			};
		}
	}
}

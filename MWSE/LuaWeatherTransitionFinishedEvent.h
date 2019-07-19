#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class WeatherTransitionFinishedEvent : public GenericEvent, public DisableableEvent<WeatherTransitionFinishedEvent> {
			public:
				WeatherTransitionFinishedEvent();
				sol::table createEventTable();
			};
		}
	}
}

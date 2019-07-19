#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class WeatherCycledEvent : public GenericEvent, public DisableableEvent<WeatherCycledEvent> {
			public:
				WeatherCycledEvent();
			};
		}
	}
}

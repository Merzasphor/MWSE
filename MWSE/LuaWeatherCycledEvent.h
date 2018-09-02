#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class WeatherCycledEvent : public GenericEvent {
			public:
				WeatherCycledEvent();
			};
		}
	}
}

#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class WeatherCycledEvent : public GenericEvent, public DisableableEvent<WeatherCycledEvent> {
	public:
		WeatherCycledEvent();
	};
}

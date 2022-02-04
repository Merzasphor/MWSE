#include "LuaWeatherCycledEvent.h"

namespace mwse::lua::event {
	WeatherCycledEvent::WeatherCycledEvent() :
		GenericEvent("weatherCycled")
	{

	}

	bool WeatherCycledEvent::m_EventEnabled = false;
}

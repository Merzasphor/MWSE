#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class WeatherChangedImmediateEvent : public GenericEvent, public DisableableEvent<WeatherChangedImmediateEvent> {
			public:
				WeatherChangedImmediateEvent();
				sol::table createEventTable();
			};
		}
	}
}

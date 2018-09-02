#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class WeatherChangedImmediateEvent : public GenericEvent {
			public:
				WeatherChangedImmediateEvent();
				sol::table createEventTable();
			};
		}
	}
}

#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class PreLevelUpEvent : public GenericEvent, public DisableableEvent<PreLevelUpEvent> {
	public:
		PreLevelUpEvent();
		sol::table createEventTable();
		sol::object getEventOptions();
	};
}

#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CalculateSoulValueEvent : public ObjectFilteredEvent, public DisableableEvent<CalculateSoulValueEvent> {
	public:
		CalculateSoulValueEvent(TES3::Actor* actor, sol::optional<int> value = {});
		sol::table createEventTable();

	protected:
		TES3::Actor* m_Actor;
		sol::optional<int> m_Value;
	};
}

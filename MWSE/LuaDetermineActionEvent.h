#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class DetermineActionEvent : public ObjectFilteredEvent, public DisableableEvent<DetermineActionEvent> {
	public:
		DetermineActionEvent(TES3::CombatSession* session);
		sol::table createEventTable();

	protected:
		TES3::CombatSession* m_Session;
	};
}

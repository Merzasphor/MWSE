#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CombatStopEvent : public ObjectFilteredEvent, public DisableableEvent<CombatStopEvent> {
	public:
		CombatStopEvent(TES3::MobileActor* mobileActor);
		sol::table createEventTable();

	protected:
		TES3::MobileActor* m_MobileActor;
	};
}

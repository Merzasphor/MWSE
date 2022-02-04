#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CombatStoppedEvent : public ObjectFilteredEvent, public DisableableEvent<CombatStoppedEvent> {
	public:
		CombatStoppedEvent(TES3::MobileActor* mobileActor);
		sol::table createEventTable();

	protected:
		TES3::MobileActor* m_MobileActor;
	};
}

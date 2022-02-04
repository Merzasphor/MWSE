#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CombatStartedEvent : public ObjectFilteredEvent, public DisableableEvent<CombatStartedEvent> {
	public:
		CombatStartedEvent(TES3::MobileActor* mobileActor, TES3::MobileActor* target);
		sol::table createEventTable();

	protected:
		TES3::MobileActor* m_MobileActor;
		TES3::MobileActor* m_Target;
	};
}

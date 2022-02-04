#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class DeathEvent : public ObjectFilteredEvent, public DisableableEvent<DeathEvent> {
	public:
		DeathEvent(TES3::MobileActor* mobileActor);
		sol::table createEventTable();

	protected:
		TES3::MobileActor* m_MobileActor;
	};
}

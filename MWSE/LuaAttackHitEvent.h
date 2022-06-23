#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class AttackHitEvent : public ObjectFilteredEvent, public DisableableEvent<AttackHitEvent> {
	public:
		AttackHitEvent(TES3::MobileActor* mobileActor);
		sol::table createEventTable();

	protected:
		TES3::MobileActor* m_MobileActor;
	};
}

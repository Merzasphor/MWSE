#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class MobileActorDeactivatedEvent : public ObjectFilteredEvent, public DisableableEvent<MobileActorDeactivatedEvent> {
	public:
		MobileActorDeactivatedEvent(TES3::Reference* reference);
		sol::table createEventTable();

	protected:
		TES3::Reference* m_Reference;
	};
}

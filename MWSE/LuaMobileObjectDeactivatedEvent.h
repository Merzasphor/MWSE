#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class MobileObjectDeactivatedEvent : public ObjectFilteredEvent, public DisableableEvent<MobileObjectDeactivatedEvent> {
	public:
		MobileObjectDeactivatedEvent(TES3::MobileObject* mobile);
		sol::table createEventTable();

	protected:
		TES3::MobileObject* m_Mobile;
	};
}

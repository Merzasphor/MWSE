#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class ReferenceDeactivatedEvent : public ObjectFilteredEvent, public DisableableEvent<ReferenceDeactivatedEvent> {
	public:
		ReferenceDeactivatedEvent(TES3::Reference* reference);
		sol::table createEventTable();

	protected:
		TES3::Reference* m_Reference;
	};
}

#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class ReferenceActivatedEvent : public ObjectFilteredEvent, public DisableableEvent<ReferenceActivatedEvent> {
	public:
		ReferenceActivatedEvent(TES3::Reference* reference);
		sol::table createEventTable();

	protected:
		TES3::Reference* m_Reference;
	};
}

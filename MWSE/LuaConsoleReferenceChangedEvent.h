#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class ConsoleReferenceChangedEvent : public ObjectFilteredEvent, public DisableableEvent<ConsoleReferenceChangedEvent> {
	public:
		ConsoleReferenceChangedEvent(TES3::Reference* reference);
		sol::table createEventTable();

	protected:
		TES3::Reference* m_Reference;
	};
}

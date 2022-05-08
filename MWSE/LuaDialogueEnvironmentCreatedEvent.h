#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class DialogueEnvironmentCreatedEvent : public GenericEvent, public DisableableEvent<DialogueEnvironmentCreatedEvent> {
	public:
		DialogueEnvironmentCreatedEvent(sol::environment environment);
		sol::table createEventTable();

	protected:
		sol::environment m_Environment;
	};
}

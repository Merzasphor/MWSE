#pragma once

#include "LuaBaseEvent.h"

namespace mwse::lua::event {
	// Generic event. Delivers no real payload and contains a dynamic name.
	class GenericEvent : public BaseEvent {
	public:
		GenericEvent(const char* name);
		const char* getEventName();

	protected:
		const char* m_EventName;
	};
}

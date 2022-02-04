#pragma once

#include "LuaGenericEvent.h"

namespace mwse::lua::event {
	GenericEvent::GenericEvent(const char* name) :
		m_EventName(name)
	{

	}

	const char* GenericEvent::getEventName() {
		return m_EventName;
	}
}

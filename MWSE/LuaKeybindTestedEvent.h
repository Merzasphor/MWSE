#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class KeybindTestedEvent : public GenericEvent, public DisableableEvent<KeybindTestedEvent> {
	public:
		KeybindTestedEvent(unsigned int keybind, unsigned int transition, bool result);
		sol::table createEventTable();
		sol::object getEventOptions();

	protected:
		unsigned int m_Keybind;
		unsigned int m_Transition;
		bool m_Result;
	};
}

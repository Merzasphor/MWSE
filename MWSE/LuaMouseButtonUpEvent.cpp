#include "LuaMouseButtonUpEvent.h"

#include "LuaManager.h"

namespace mwse::lua::event {
	MouseButtonUpEvent::MouseButtonUpEvent(int button, bool controlDown, bool shiftDown, bool altDown, bool superDown) :
		KeyEvent(button, true, controlDown, shiftDown, altDown, superDown)
	{
		m_EventName = "mouseButtonUp";
	}

	sol::table MouseButtonUpEvent::createEventTable() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table eventData = state.create_table();

		eventData["button"] = m_KeyCode;

		return eventData;
	}

	bool MouseButtonUpEvent::m_EventEnabled = false;
}

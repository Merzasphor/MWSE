#include "LuaMouseButtonDownEvent.h"

#include "LuaManager.h"

namespace mwse::lua::event {
	MouseButtonDownEvent::MouseButtonDownEvent(int button, bool controlDown, bool shiftDown, bool altDown, bool superDown) :
		KeyEvent(button, true, controlDown, shiftDown, altDown, superDown)
	{
		m_EventName = "mouseButtonDown";
	}

	sol::table MouseButtonDownEvent::createEventTable() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table eventData = state.create_table();

		eventData["button"] = m_KeyCode;

		return eventData;
	}

	bool MouseButtonDownEvent::m_EventEnabled = false;
}

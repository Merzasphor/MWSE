#include "LuaMouseButtonUpEvent.h"

#include "LuaManager.h"

namespace mwse {
	namespace lua {
		namespace event {
			MouseButtonUpEvent::MouseButtonUpEvent(int button, bool controlDown, bool shiftDown, bool altDown, bool superDown) :
				KeyEvent(button, true, controlDown, shiftDown, altDown, superDown)
			{
				m_EventName = "mouseButtonUp";
			}

			sol::table MouseButtonUpEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = KeyEvent::createEventTable();

				eventData["button"] = m_KeyCode;

				return eventData;
			}
		}
	}
}

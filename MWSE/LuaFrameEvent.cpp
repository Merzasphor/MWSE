#include "LuaFrameEvent.h"

#include "LuaManager.h"

namespace mwse {
	namespace lua {
		namespace event {
			FrameEvent::FrameEvent(float delta, bool menuMode) :
				GenericEvent("enterFrame"),
				m_Delta(delta),
				m_MenuMode(menuMode)
			{

			}

			sol::table FrameEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["menuMode"] = m_MenuMode;
				eventData["delta"] = m_Delta;

				return eventData;
			}

			bool FrameEvent::m_EventEnabled = false;
		}
	}
}

#include "LuaSimulateEvent.h"

#include "LuaManager.h"

namespace mwse {
	namespace lua {
		namespace event {
			SimulateEvent::SimulateEvent(float delta, double timestamp) :
				GenericEvent("simulate"),
				m_Delta(delta)
			{

			}

			sol::table SimulateEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["menuMode"] = false;
				eventData["delta"] = m_Delta;
				eventData["timestamp"] = m_Timestamp;

				return eventData;
			}

			bool SimulateEvent::m_EventEnabled = false;
		}
	}
}

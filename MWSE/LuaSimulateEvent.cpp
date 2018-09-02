#include "LuaSimulateEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			SimulateEvent::SimulateEvent(float delta, double timestamp) :
				FrameEvent(delta, false),
				m_Timestamp(timestamp)
			{
				m_EventName = "simulate";
			}

			sol::table SimulateEvent::createEventTable() {
				sol::table eventData = FrameEvent::createEventTable();

				eventData["timestamp"] = m_Timestamp;

				return eventData;
			}
		}
	}
}

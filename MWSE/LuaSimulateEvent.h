#pragma once

#include "LuaFrameEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			// As FrameEvent, but limited to when simulation is occuring.
			class SimulateEvent : public FrameEvent {
			public:
				SimulateEvent(float delta, double timestamp);
				sol::table createEventTable();

			protected:
				double m_Timestamp;
			};
		}
	}
}

#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			// Enter frame event.
			class SimulateEvent : public GenericEvent, public DisableableEvent<SimulateEvent> {
			public:
				SimulateEvent(float delta, double timestamp);
				sol::table createEventTable();

			protected:
				float m_Delta;
				double m_Timestamp;
			};
		}
	}
}

#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
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

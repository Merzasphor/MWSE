#include "LuaMusicSelectTrackEvent.h"

#include "LuaManager.h"

namespace mwse::lua::event {
	MusicSelectTrackEvent::MusicSelectTrackEvent(int situation) :
		GenericEvent("musicSelectTrack"),
		m_Situation(situation)
	{

	}

	sol::table MusicSelectTrackEvent::createEventTable() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table eventData = state.create_table();
		eventData["situation"] = m_Situation;
		return eventData;
	}

	bool MusicSelectTrackEvent::m_EventEnabled = false;
}

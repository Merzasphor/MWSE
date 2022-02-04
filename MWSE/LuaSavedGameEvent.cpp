#include "LuaSavedGameEvent.h"

#include "LuaManager.h"

namespace mwse::lua::event {
	SavedGameEvent::SavedGameEvent(const char* saveName, const char* fileName) :
		GenericEvent("saved"),
		m_SaveName(saveName),
		m_FileName(fileName)
	{

	}

	sol::table SavedGameEvent::createEventTable() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table eventData = state.create_table();

		eventData["name"] = m_SaveName;
		eventData["filename"] = m_FileName;

		return eventData;
	}

	sol::object SavedGameEvent::getEventOptions() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table options = state.create_table();

		options["filter"] = m_FileName;

		return options;
	}

	bool SavedGameEvent::m_EventEnabled = false;
}

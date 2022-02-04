#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class SavedGameEvent : public GenericEvent, public DisableableEvent<SavedGameEvent> {
	public:
		SavedGameEvent(const char* saveName, const char* fileName);
		sol::table createEventTable();
		sol::object getEventOptions();

	protected:
		const char* m_SaveName;
		const char* m_FileName;
	};
}

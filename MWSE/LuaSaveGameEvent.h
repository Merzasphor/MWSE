#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class SaveGameEvent : public GenericEvent, public DisableableEvent<SaveGameEvent> {
	public:
		SaveGameEvent(const char* saveName, const char* fileName);
		sol::table createEventTable();
		sol::object getEventOptions();

	protected:
		const char* m_SaveName;
		const char* m_FileName;
	};
}

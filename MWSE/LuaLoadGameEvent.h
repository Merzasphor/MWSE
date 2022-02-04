#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class LoadGameEvent : public GenericEvent, public DisableableEvent<LoadGameEvent> {
	public:
		LoadGameEvent(const char* fileName, bool quickLoad = false, bool newGame = false);
		sol::table createEventTable();
		sol::object getEventOptions();

	protected:
		const char* m_FileName;
		bool m_QuickLoad;
		bool m_NewGame;
	};
}

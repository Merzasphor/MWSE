#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class ShowRestWaitMenuEvent : public GenericEvent, public DisableableEvent<ShowRestWaitMenuEvent> {
	public:
		ShowRestWaitMenuEvent(bool allowRest, bool scripted);
		sol::table createEventTable();

	protected:
		bool m_AllowRest;
		bool m_Scripted;
	};
}

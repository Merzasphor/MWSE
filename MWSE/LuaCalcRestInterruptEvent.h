#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CalcRestInterruptEvent : public GenericEvent, public DisableableEvent<CalcRestInterruptEvent> {
	public:
		CalcRestInterruptEvent(int count, int hour);
		sol::table createEventTable();

	protected:
		int m_Count;
		int m_Hour;
	};
}

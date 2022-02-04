#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class MouseWheelEvent : public GenericEvent, public DisableableEvent<MouseWheelEvent> {
	public:
		MouseWheelEvent(int delta, bool controlDown, bool shiftDown, bool altDown, bool superDown);
		sol::table createEventTable();

	protected:
		int m_Delta;
		bool m_ControlDown;
		bool m_ShiftDown;
		bool m_AltDown;
		bool m_SuperDown;
	};
}

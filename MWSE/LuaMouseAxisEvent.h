#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class MouseAxisEvent : public GenericEvent, public DisableableEvent<MouseAxisEvent> {
	public:
		MouseAxisEvent(int deltaX, int deltaY, bool controlDown, bool shiftDown, bool altDown, bool superDown);
		sol::table createEventTable();

	protected:
		int m_DeltaX;
		int m_DeltaY;
		bool m_ControlDown;
		bool m_ShiftDown;
		bool m_AltDown;
		bool m_SuperDown;
	};
}

#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	// Not to be used directly.
	class KeyEvent : public GenericEvent {
	public:
		KeyEvent(int keyCode, bool pressed, bool controlDown, bool shiftDown, bool altDown, bool superDown);
		sol::table createEventTable();
		sol::object getEventOptions();

	protected:
		int m_KeyCode;
		bool m_Pressed;
		bool m_ControlDown;
		bool m_ShiftDown;
		bool m_AltDown;
		bool m_SuperDown;
	};
}

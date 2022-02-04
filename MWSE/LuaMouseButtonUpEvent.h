#pragma once

#include "LuaKeyEvent.h"

namespace mwse::lua::event {
	class MouseButtonUpEvent : public KeyEvent, public DisableableEvent<MouseButtonUpEvent> {
	public:
		MouseButtonUpEvent(int button, bool controlDown, bool shiftDown, bool altDown, bool superDown);
		sol::table createEventTable();
	};
}

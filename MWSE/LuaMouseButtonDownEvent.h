#pragma once

#include "LuaKeyEvent.h"

namespace mwse::lua::event {
	class MouseButtonDownEvent : public KeyEvent, public DisableableEvent<MouseButtonDownEvent> {
	public:
		MouseButtonDownEvent(int button, bool controlDown, bool shiftDown, bool altDown, bool superDown);
		sol::table createEventTable();
	};
}

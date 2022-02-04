#pragma once

#include "LuaKeyEvent.h"

namespace mwse::lua::event {
	class KeyDownEvent : public KeyEvent, public DisableableEvent<KeyDownEvent> {
	public:
		KeyDownEvent(int keyCode, bool controlDown, bool shiftDown, bool altDown, bool superDown);
	};
}

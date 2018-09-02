#pragma once

#include "LuaKeyEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class KeyDownEvent : public KeyEvent {
			public:
				KeyDownEvent(int keyCode, bool controlDown, bool shiftDown, bool altDown, bool superDown);
			};
		}
	}
}

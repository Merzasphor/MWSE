#pragma once

#include "LuaKeyEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class KeyUpEvent : public KeyEvent {
			public:
				KeyUpEvent(int keyCode, bool controlDown, bool shiftDown, bool altDown, bool superDown);
			};
		}
	}
}

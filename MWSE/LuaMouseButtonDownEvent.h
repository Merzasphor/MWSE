#pragma once

#include "LuaKeyEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class MouseButtonDownEvent : public KeyEvent {
			public:
				MouseButtonDownEvent(int button, bool controlDown, bool shiftDown, bool altDown, bool superDown);
				sol::table createEventTable();
			};
		}
	}
}

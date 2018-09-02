#pragma once

#include "LuaKeyEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class MouseButtonUpEvent : public KeyEvent {
			public:
				MouseButtonUpEvent(int button, bool controlDown, bool shiftDown, bool altDown, bool superDown);
				sol::table createEventTable();
			};
		}
	}
}

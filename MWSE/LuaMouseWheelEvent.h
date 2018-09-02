#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class MouseWheelEvent : public GenericEvent {
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
	}
}

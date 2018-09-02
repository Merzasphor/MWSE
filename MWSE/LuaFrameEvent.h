#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			// Enter frame event.
			class FrameEvent : public GenericEvent {
			public:
				FrameEvent(float delta, bool menuMode);
				sol::table createEventTable();

			protected:
				bool m_MenuMode;
				float m_Delta;
			};
		}
	}
}

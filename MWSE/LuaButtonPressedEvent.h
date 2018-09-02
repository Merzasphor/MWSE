#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class ButtonPressedEvent : public GenericEvent {
			public:
				ButtonPressedEvent(int buttonId);
				sol::table createEventTable();

			protected:
				int m_ButtonId;
			};
		}
	}
}

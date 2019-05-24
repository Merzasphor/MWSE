#pragma once

#include "LuaBaseEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class MenuStateEvent : public BaseEvent, public DisableableEvent<MenuStateEvent> {
			public:
				MenuStateEvent(bool inMenuMode);
				const char* getEventName();
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				bool m_InMenuMode;
			};
		}
	}
}

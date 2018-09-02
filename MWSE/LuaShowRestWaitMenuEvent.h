#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class ShowRestWaitMenuEvent : public GenericEvent {
			public:
				ShowRestWaitMenuEvent(bool allowRest, bool scripted);
				sol::table createEventTable();

			protected:
				bool m_AllowRest;
				bool m_Scripted;
			};
		}
	}
}

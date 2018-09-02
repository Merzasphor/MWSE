#pragma once

#include "LuaGenericEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			// 
			class ObjectFilteredEvent : public GenericEvent {
			public:
				ObjectFilteredEvent(const char* name, TES3::BaseObject* filter);
				sol::object getEventOptions();

			protected:
				TES3::BaseObject* m_EventFilter;
			};
		}
	}
}

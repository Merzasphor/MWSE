#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class ActivateEvent : public ObjectFilteredEvent {
			public:
				ActivateEvent(TES3::Reference* activator, TES3::Reference* target);
				sol::table createEventTable();

			protected:
				TES3::Reference* m_Activator;
				TES3::Reference* m_Target;
			};
		}
	}
}

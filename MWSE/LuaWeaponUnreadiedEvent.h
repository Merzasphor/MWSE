#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class WeaponUnreadiedEvent : public ObjectFilteredEvent {
			public:
				WeaponUnreadiedEvent(TES3::Reference* reference);
				sol::table createEventTable();

			protected:
				TES3::Reference* m_Reference;
			};
		}
	}
}

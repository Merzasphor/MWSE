#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class MobileActorDeactivatedEvent : public ObjectFilteredEvent {
			public:
				MobileActorDeactivatedEvent(TES3::Reference * reference);
				sol::table createEventTable();

			protected:
				TES3::Reference* m_Reference;
			};
		}
	}
}

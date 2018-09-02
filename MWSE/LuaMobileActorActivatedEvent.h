#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class MobileActorActivatedEvent : public ObjectFilteredEvent {
			public:
				MobileActorActivatedEvent(TES3::Reference * reference);
				sol::table createEventTable();

			protected:
				TES3::Reference* m_Reference;
			};
		}
	}
}

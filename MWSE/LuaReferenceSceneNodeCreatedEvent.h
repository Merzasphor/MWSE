#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class ReferenceSceneNodeCreatedEvent : public ObjectFilteredEvent {
			public:
				ReferenceSceneNodeCreatedEvent(TES3::Reference* activator);
				sol::table createEventTable();

			protected:
				TES3::Reference* m_Reference;
			};
		}
	}
}

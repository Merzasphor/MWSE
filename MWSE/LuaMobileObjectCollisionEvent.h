#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class MobileObjectCollisionEvent : public ObjectFilteredEvent {
			public:
				MobileObjectCollisionEvent(TES3::MobileObject* mobileObject, TES3::Reference* targetReference);
				sol::table createEventTable();

			protected:
				TES3::MobileObject* m_MobileObject;
				TES3::Reference* m_TargetReference;
			};
		}
	}
}

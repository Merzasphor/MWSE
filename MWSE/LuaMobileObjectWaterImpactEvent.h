#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class MobileObjectWaterImpactEvent : public ObjectFilteredEvent {
			public:
				MobileObjectWaterImpactEvent(TES3::MobileObject* mobileObject, bool inWater);
				sol::table createEventTable();

			protected:
				TES3::MobileObject* m_MobileObject;
				bool m_InWater;
			};
		}
	}
}

#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class MobileObjectWaterImpactEvent : public ObjectFilteredEvent, public DisableableEvent<MobileObjectWaterImpactEvent> {
	public:
		MobileObjectWaterImpactEvent(TES3::MobileObject* mobileObject, bool inWater);
		sol::table createEventTable();

	protected:
		TES3::MobileObject* m_MobileObject;
		bool m_InWater;
	};
}

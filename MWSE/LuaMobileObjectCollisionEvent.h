#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class MobileObjectCollisionEvent : public ObjectFilteredEvent, public DisableableEvent<MobileObjectCollisionEvent> {
	public:
		MobileObjectCollisionEvent(TES3::MobileObject* mobileObject, TES3::Reference* targetReference);
		sol::table createEventTable();

	protected:
		TES3::MobileObject* m_MobileObject;
		TES3::Reference* m_TargetReference;
	};
}

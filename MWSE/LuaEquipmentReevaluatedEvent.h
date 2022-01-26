#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class EquipmentReevaluatedEvent : public ObjectFilteredEvent, public DisableableEvent<EquipmentReevaluatedEvent> {
	public:
		EquipmentReevaluatedEvent(TES3::Actor* actor);
		sol::table createEventTable();

	protected:
		TES3::Actor* m_Actor;
	};
}
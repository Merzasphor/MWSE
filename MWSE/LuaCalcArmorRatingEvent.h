#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CalculateArmorRatingEvent : public ObjectFilteredEvent, public DisableableEvent<CalculateArmorRatingEvent> {
	public:
		CalculateArmorRatingEvent(TES3::Armor* armor, TES3::MobileActor* actor);
		CalculateArmorRatingEvent(TES3::Armor* armor, TES3::NPC* npc);
		sol::table createEventTable();

	protected:
		TES3::Armor* m_Armor;
		TES3::MobileActor* m_Actor;
		TES3::NPC* m_NPC;
	};
}

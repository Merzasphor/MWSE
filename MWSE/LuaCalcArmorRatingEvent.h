#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CalculateArmorRatingEvent : public ObjectFilteredEvent {
			public:
				CalculateArmorRatingEvent(TES3::Armor * armor, TES3::MobileActor * actor);
				CalculateArmorRatingEvent(TES3::Armor * armor, TES3::NPC * npc);
				sol::table createEventTable();

			protected:
				TES3::Armor* m_Armor;
				TES3::MobileActor* m_Actor;
				TES3::NPC* m_NPC;
			};
		}
	}
}

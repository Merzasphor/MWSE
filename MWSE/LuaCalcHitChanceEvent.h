#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CalcHitChanceEvent : public ObjectFilteredEvent {
			public:
				CalcHitChanceEvent(TES3::MobileActor * attacker, int hitChance);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_Attacker;
				int m_HitChance;
			};
		}
	}
}

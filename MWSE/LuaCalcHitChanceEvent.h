#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CalcHitChanceEvent : public ObjectFilteredEvent, public DisableableEvent<CalcHitChanceEvent> {
	public:
		CalcHitChanceEvent(int hitChance);
		sol::table createEventTable();

		static TES3::MobileActor* m_Attacker;
		static TES3::MobileProjectile* m_Projectile;

	protected:
		int m_HitChance;
	};
}

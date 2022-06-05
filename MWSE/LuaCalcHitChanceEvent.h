#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CalcHitChanceEvent : public ObjectFilteredEvent, public DisableableEvent<CalcHitChanceEvent> {
	public:
		CalcHitChanceEvent(TES3::MobileActor* attacker, TES3::MobileProjectile* projectile, int hitChance);
		sol::table createEventTable();

	protected:
		TES3::MobileActor* m_Attacker;
		TES3::MobileProjectile* m_Projectile;
		int m_HitChance;
	};
}

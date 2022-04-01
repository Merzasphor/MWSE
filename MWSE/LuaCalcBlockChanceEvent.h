#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CalcBlockChanceEvent : public ObjectFilteredEvent, public DisableableEvent<CalcBlockChanceEvent> {
	public:
		CalcBlockChanceEvent(TES3::MobileActor* attacker, int blockChance);
		sol::table createEventTable();

	protected:
		TES3::MobileActor* m_Attacker;
		int m_BlockChance;
	};
}

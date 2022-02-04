#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CalculateSpellPriceEvent : public ObjectFilteredEvent, public DisableableEvent<CalculateSpellPriceEvent> {
	public:
		CalculateSpellPriceEvent(TES3::MobileActor* mobileActor, int basePrice, int price, TES3::Spell* spell);
		sol::table createEventTable();

	protected:
		TES3::MobileActor* m_MobileActor;
		int m_BasePrice;
		int m_Price;
		TES3::Spell* m_Spell;
	};
}

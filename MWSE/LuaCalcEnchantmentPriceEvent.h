#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CalculateEnchantmentPriceEvent : public ObjectFilteredEvent, public DisableableEvent<CalculateEnchantmentPriceEvent> {
	public:
		CalculateEnchantmentPriceEvent(TES3::MobileActor* serviceActor, int basePrice, int price);
		sol::table createEventTable();

	protected:
		TES3::MobileActor* m_ServiceActor;
		int m_BasePrice;
		int m_Price;
	};
}

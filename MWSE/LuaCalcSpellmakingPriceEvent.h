#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CalculateSpellmakingPriceEvent : public ObjectFilteredEvent, public DisableableEvent<CalculateSpellmakingPriceEvent> {
	public:
		CalculateSpellmakingPriceEvent(TES3::MobileActor* serviceActor, float price);
		sol::table createEventTable();

	protected:
		TES3::MobileActor* m_ServiceActor;
		float m_Price;
	};
}

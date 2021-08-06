#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Alchemy.h"


namespace mwse::lua::event {
	class PotionBrewFailedEvent : public GenericEvent, public DisableableEvent<PotionBrewFailedEvent> {
	public:
		PotionBrewFailedEvent(const TES3::AlchemyBrewingItems& items);
		sol::table createEventTable();

	protected:
		TES3::AlchemyBrewingItems m_Items;
	};
}

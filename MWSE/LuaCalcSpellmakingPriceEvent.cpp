#include "LuaCalcSpellmakingPriceEvent.h"

#include "LuaManager.h"

#include "TES3MobileActor.h"
#include "TES3Reference.h"

namespace mwse::lua::event {
	CalculateSpellmakingPriceEvent::CalculateSpellmakingPriceEvent(TES3::MobileActor* serviceActor, float price) :
		ObjectFilteredEvent("calcSpellmakingPrice", serviceActor->reference),
		m_ServiceActor(serviceActor),
		m_Price(price)
	{

	}

	sol::table CalculateSpellmakingPriceEvent::createEventTable() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table eventData = state.create_table();

		eventData["mobile"] = m_ServiceActor;
		if (m_ServiceActor) {
			eventData["reference"] = m_ServiceActor->reference;
		}

		eventData["price"] = m_Price;

		return eventData;
	}

	bool CalculateSpellmakingPriceEvent::m_EventEnabled = false;
}

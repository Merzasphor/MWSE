#include "LuaUpdatedDerivedStatisticsEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3MobileActor.h"
#include "TES3Reference.h"
#include "TES3MobileActor.h"

namespace mwse::lua::event {
	UpdatedDerivedStatisticsEvent::UpdatedDerivedStatisticsEvent(TES3::MobileActor* mobile, TES3::Statistic* statistic, const char* name) :
		GenericEvent("updatedDerivedStatistics"),
		m_MobileActor(mobile),
		m_Statistic(statistic),
		m_StatisticName(name)
	{

	}

	sol::table UpdatedDerivedStatisticsEvent::createEventTable() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table eventData = state.create_table();

		eventData["mobile"] = m_MobileActor;
		eventData["reference"] = m_MobileActor->reference;
		eventData["statistic"] = m_Statistic;
		eventData["name"] = m_StatisticName;

		return eventData;
	}

	sol::object UpdatedDerivedStatisticsEvent::getEventOptions() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table options = state.create_table();

		options["filter"] = m_StatisticName;

		return options;
	}

	bool UpdatedDerivedStatisticsEvent::m_EventEnabled = false;
}

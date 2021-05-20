#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			class UpdatedDerivedStatisticsEvent : public GenericEvent, public DisableableEvent<UpdatedDerivedStatisticsEvent> {
			public:
				UpdatedDerivedStatisticsEvent(TES3::MobileActor* mobile, TES3::Statistic* statistic, const char* name);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				TES3::MobileActor* m_MobileActor;
				TES3::Statistic* m_Statistic;
				const char* m_StatisticName;
			};
		}
	}
}

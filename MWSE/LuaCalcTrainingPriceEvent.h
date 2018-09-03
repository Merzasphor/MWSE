#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CalculateTrainingPriceEvent : public ObjectFilteredEvent {
			public:
				CalculateTrainingPriceEvent(TES3::MobileActor * mobileActor, int basePrice, int price, int skillId);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_MobileActor;
				int m_BasePrice;
				int m_Price;
				int m_SkillId;
			};
		}
	}
}

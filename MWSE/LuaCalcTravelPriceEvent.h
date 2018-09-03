#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CalculateTravelPriceEvent : public ObjectFilteredEvent {
			public:
				CalculateTravelPriceEvent(TES3::MobileActor * mobileActor, int basePrice, int price, TES3::TravelDestination * destination, std::vector<TES3::MobileActor*>* companionList, float distance = NAN);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_MobileActor;
				int m_BasePrice;
				int m_Price;
				TES3::TravelDestination* m_Destination;
				std::vector<TES3::MobileActor*>* m_CompanionList;
				float m_Distance;
			};
		}
	}
}

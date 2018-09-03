#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CalculateBarterPriceEvent : public ObjectFilteredEvent {
			public:
				CalculateBarterPriceEvent(TES3::MobileActor * mobileActor, int basePrice, int price, bool buying, int count = 1, TES3::EquipmentStack* item = nullptr);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_MobileActor;
				int m_BasePrice;
				int m_Price;
				bool m_Buying;
				int m_Count;
				TES3::EquipmentStack* m_Stack;
			};
		}
	}
}

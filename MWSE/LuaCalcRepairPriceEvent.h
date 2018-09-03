#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CalculateRepairPriceEvent : public ObjectFilteredEvent {
			public:
				CalculateRepairPriceEvent(TES3::MobileActor * mobileActor, int basePrice, int price, TES3::ItemStack* stack);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_MobileActor;
				int m_BasePrice;
				int m_Price;
				TES3::ItemStack* m_Stack;
			};
		}
	}
}

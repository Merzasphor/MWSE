#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CalculateRepairPriceEvent : public ObjectFilteredEvent, public DisableableEvent<CalculateRepairPriceEvent> {
	public:
		CalculateRepairPriceEvent(TES3::MobileActor* mobileActor, int basePrice, int price, TES3::Object* item, TES3::ItemData* itemData = nullptr);
		sol::table createEventTable();

	protected:
		TES3::MobileActor* m_MobileActor;
		int m_BasePrice;
		int m_Price;
		TES3::Object* m_Item;
		TES3::ItemData* m_ItemData;
	};
}

#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CalculateBarterPriceEvent : public ObjectFilteredEvent, public DisableableEvent<CalculateBarterPriceEvent> {
	public:
		CalculateBarterPriceEvent(TES3::MobileActor* mobileActor, int basePrice, int price, bool buying, int count = 1, TES3::Object* item = nullptr, TES3::ItemData* itemData = nullptr);
		sol::table createEventTable();

	protected:
		TES3::MobileActor* m_MobileActor;
		int m_BasePrice;
		int m_Price;
		bool m_Buying;
		int m_Count;
		TES3::Object* m_Item;
		TES3::ItemData* m_ItemData;
	};
}

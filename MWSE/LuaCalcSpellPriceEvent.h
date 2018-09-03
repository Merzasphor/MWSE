#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CalculateSpellPriceEvent : public ObjectFilteredEvent {
			public:
				CalculateSpellPriceEvent(TES3::MobileActor * mobileActor, int basePrice, int price, TES3::Spell* spell);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_MobileActor;
				int m_BasePrice;
				int m_Price;
				TES3::Spell* m_Spell;
			};
		}
	}
}

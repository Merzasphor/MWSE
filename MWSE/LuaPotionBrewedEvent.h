#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Alchemy.h"

namespace mwse {
	namespace lua {
		namespace event {
			class PotionBrewedEvent : public GenericEvent, public DisableableEvent<PotionBrewedEvent> {
			public:
				PotionBrewedEvent(TES3::Alchemy* object, const TES3::AlchemyBrewingItems& items);
				sol::table createEventTable();

			protected:
				TES3::Alchemy* m_Object;
				TES3::AlchemyBrewingItems m_Items;
			};
		}
	}
}

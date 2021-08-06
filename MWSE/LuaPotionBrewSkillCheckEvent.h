#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Alchemy.h"

namespace mwse {
	namespace lua {
		namespace event {
			class PotionBrewSkillCheckEvent : public GenericEvent, public DisableableEvent<PotionBrewSkillCheckEvent> {
			public:
				PotionBrewSkillCheckEvent(float potionStrength, const TES3::AlchemyBrewingItems& items);
				sol::table createEventTable();

			protected:
				float m_PotionStrength;
				TES3::AlchemyBrewingItems m_Items;
			};
		}
	}
}

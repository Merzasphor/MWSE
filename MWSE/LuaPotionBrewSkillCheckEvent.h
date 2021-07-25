#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			class PotionBrewSkillCheckEvent : public GenericEvent, public DisableableEvent<PotionBrewSkillCheckEvent> {
			public:
				PotionBrewSkillCheckEvent(float potionStrength);
				sol::table createEventTable();

			protected:
				float m_PotionStrength;
			};
		}
	}
}

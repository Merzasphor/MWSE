#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			class PotionBrewedEvent : public GenericEvent, public DisableableEvent<PotionBrewedEvent> {
			public:
				PotionBrewedEvent(TES3::Alchemy * object);
				sol::table createEventTable();

			protected:
				TES3::Alchemy * m_Object;
			};
		}
	}
}

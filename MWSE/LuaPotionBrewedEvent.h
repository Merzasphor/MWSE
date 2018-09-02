#pragma once

#include "LuaGenericEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			class PotionBrewedEvent : public GenericEvent {
			public:
				PotionBrewedEvent(TES3::Alchemy * object);
				sol::table createEventTable();

			protected:
				TES3::Alchemy * m_Object;
			};
		}
	}
}

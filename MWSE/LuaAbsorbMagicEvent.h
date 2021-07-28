#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class AbsorbMagicEvent : public ObjectFilteredEvent, public DisableableEvent<AbsorbMagicEvent> {
			public:
				AbsorbMagicEvent(TES3::MobileActor * actor, TES3::MagicSourceInstance * instance, float absorb);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_MobileActor;
				TES3::MagicSourceInstance* m_MagicSourceInstance;
				float m_Absorb;
			};
		}
	}
}

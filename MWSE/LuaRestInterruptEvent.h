#pragma once

#include "LuaGenericEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			class RestInterruptEvent : public GenericEvent {
			public:
				RestInterruptEvent(TES3::LeveledCreature * leveledCreature);
				sol::table createEventTable();

			protected:
				TES3::LeveledCreature * m_Creature;
			};
		}
	}
}

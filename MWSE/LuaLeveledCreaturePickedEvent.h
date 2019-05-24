#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class LeveledCreaturePickedEvent : public ObjectFilteredEvent, public DisableableEvent<LeveledCreaturePickedEvent> {
			public:
				LeveledCreaturePickedEvent(TES3::LeveledCreature * list, TES3::Object * vanillaResult);
				sol::table createEventTable();

			protected:
				TES3::LeveledCreature* m_List;
				TES3::Object* m_Result;
			};
		}
	}
}

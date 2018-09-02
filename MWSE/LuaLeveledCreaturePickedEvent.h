#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class LeveledCreaturePickedEvent : public ObjectFilteredEvent {
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

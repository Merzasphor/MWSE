#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class LeveledItemPickedEvent : public ObjectFilteredEvent {
			public:
				LeveledItemPickedEvent(TES3::LeveledItem * list, TES3::Object * vanillaResult);
				sol::table createEventTable();

			protected:
				TES3::LeveledItem* m_List;
				TES3::Object* m_Result;
			};
		}
	}
}

#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CellChangedEvent : public ObjectFilteredEvent {
			public:
				CellChangedEvent(TES3::Cell* cell, TES3::Cell* previousCell);
				sol::table createEventTable();

			protected:
				TES3::Cell* m_Cell;
				TES3::Cell* m_PreviousCell;
			};
		}
	}
}

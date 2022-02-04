#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CellChangedEvent : public ObjectFilteredEvent, public DisableableEvent<CellChangedEvent> {
	public:
		CellChangedEvent(TES3::Cell* cell, TES3::Cell* previousCell);
		sol::table createEventTable();

	protected:
		TES3::Cell* m_Cell;
		TES3::Cell* m_PreviousCell;
	};
}

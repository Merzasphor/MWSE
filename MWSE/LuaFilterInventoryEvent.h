#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class FilterInventoryEvent : public ObjectFilteredEvent, public DisableableEvent<FilterInventoryEvent> {
	public:
		FilterInventoryEvent(TES3::UI::InventoryTile* tile, TES3::Item* item);
		sol::table createEventTable();

	protected:
		TES3::UI::InventoryTile* m_Tile;
		TES3::Item* m_Item;
	};
}

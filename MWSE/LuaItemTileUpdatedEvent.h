#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Defines.h"

namespace mwse::lua::event {
	class ItemTileUpdatedEvent : public GenericEvent, public DisableableEvent<ItemTileUpdatedEvent> {
	public:
		ItemTileUpdatedEvent(TES3::UI::InventoryTile* tile);
		sol::table createEventTable();
		sol::object getEventOptions();

	protected:
		TES3::UI::InventoryTile* m_Tile;
	};
}

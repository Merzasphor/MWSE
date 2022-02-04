#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class EquipEvent : public ObjectFilteredEvent, public DisableableEvent<EquipEvent> {
	public:
		EquipEvent(TES3::Reference* reference, TES3::BaseObject* item, TES3::ItemData* itemData);
		sol::table createEventTable();

	protected:
		TES3::Reference* m_Reference;
		TES3::BaseObject* m_Item;
		TES3::ItemData* m_ItemData;
	};
}

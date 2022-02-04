#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class ItemDroppedEvent : public ObjectFilteredEvent, public DisableableEvent<ItemDroppedEvent> {
	public:
		ItemDroppedEvent(TES3::Reference* reference);
		sol::table createEventTable();

	protected:
		TES3::Reference* m_Reference;
	};
}

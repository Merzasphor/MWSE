#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class LeveledItemPickedEvent : public ObjectFilteredEvent, public DisableableEvent<LeveledItemPickedEvent> {
	public:
		LeveledItemPickedEvent(TES3::LeveledItem* list, TES3::PhysicalObject* vanillaResult);
		sol::table createEventTable();

		static TES3::Reference* m_Reference;

	protected:
		TES3::LeveledItem* m_List;
		TES3::PhysicalObject* m_Result;
	};
}

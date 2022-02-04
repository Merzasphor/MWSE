#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Defines.h"

namespace mwse::lua::event {
	class RestInterruptEvent : public GenericEvent, public DisableableEvent<RestInterruptEvent> {
	public:
		RestInterruptEvent(TES3::LeveledCreature* leveledCreature);
		sol::table createEventTable();

	protected:
		TES3::LeveledCreature* m_Creature;
	};
}

#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class DispositionEvent : public ObjectFilteredEvent, public DisableableEvent<DispositionEvent> {
	public:
		DispositionEvent(TES3::NPCInstance* npc, int disposition, bool clamp);
		sol::table createEventTable();

	protected:
		TES3::NPCInstance* m_NPC;
		int m_Disposition;
		bool m_Clamp;
	};
}

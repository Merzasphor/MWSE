#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Defines.h"

namespace mwse::lua::event {
	class UiSpellTooltipEvent : public ObjectFilteredEvent, public DisableableEvent<UiSpellTooltipEvent> {
	public:
		UiSpellTooltipEvent(TES3::UI::Element* tooltip, TES3::Spell* spell);
		sol::table createEventTable();

	protected:
		TES3::UI::Element* m_Tooltip;
		TES3::Spell* m_Spell;
	};
}

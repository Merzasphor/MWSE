#pragma once

#include "LuaObjectFilteredEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			class UiSpellTooltipEvent : public ObjectFilteredEvent {
			public:
				UiSpellTooltipEvent(TES3::UI::Element* tooltip, TES3::Spell* spell);
				sol::table createEventTable();

			protected:
				TES3::UI::Element* m_Tooltip;
				TES3::Spell* m_Spell;
			};
		}
	}
}

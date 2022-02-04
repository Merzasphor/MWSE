#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Defines.h"

namespace mwse::lua::event {
	class SpellMagickaUseEvent : public GenericEvent, public DisableableEvent<SpellMagickaUseEvent> {
	public:
		SpellMagickaUseEvent(TES3::MagicSourceInstance* source);
		sol::table createEventTable();
		sol::object getEventOptions();

	protected:
		TES3::MagicSourceInstance* m_Source;
	};
}

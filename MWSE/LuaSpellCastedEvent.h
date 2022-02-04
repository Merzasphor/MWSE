#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Defines.h"

namespace mwse::lua::event {
	class SpellCastedEvent : public GenericEvent, public DisableableEvent<SpellCastedEvent> {
	public:
		SpellCastedEvent(TES3::MagicSourceInstance* magicInstance, bool success, int expGainSchool);
		sol::table createEventTable();
		sol::object getEventOptions();

	protected:
		TES3::MagicSourceInstance* m_MagicSourceInstance;
		int m_ExpGainSchool;
	};
}

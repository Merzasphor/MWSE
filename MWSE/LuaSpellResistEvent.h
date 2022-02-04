#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Defines.h"

namespace mwse::lua::event {
	class SpellResistEvent : public GenericEvent, public DisableableEvent<SpellResistEvent> {
	public:
		SpellResistEvent(TES3::MagicSourceInstance* spellInstance, TES3::MagicEffectInstance* effectInstance, int effectIndex, int resistAttribute);
		sol::table createEventTable();
		sol::object getEventOptions();

	protected:
		TES3::MagicSourceInstance* m_MagicSourceInstance;
		TES3::MagicEffectInstance* m_EffectInstance;
		int m_EffectIndex;
		int m_ResistAttribute;
	};
}

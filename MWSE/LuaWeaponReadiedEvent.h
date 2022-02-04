#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class WeaponReadiedEvent : public ObjectFilteredEvent, public DisableableEvent<WeaponReadiedEvent> {
	public:
		WeaponReadiedEvent(TES3::Reference* reference);
		sol::table createEventTable();

	protected:
		TES3::Reference* m_Reference;
	};
}

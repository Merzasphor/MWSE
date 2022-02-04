#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class WeaponUnreadiedEvent : public ObjectFilteredEvent, public DisableableEvent<WeaponUnreadiedEvent> {
	public:
		WeaponUnreadiedEvent(TES3::Reference* reference);
		sol::table createEventTable();

	protected:
		TES3::Reference* m_Reference;
	};
}

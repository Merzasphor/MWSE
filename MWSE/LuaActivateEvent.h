#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class ActivateEvent : public ObjectFilteredEvent, public DisableableEvent<ActivateEvent> {
	public:
		ActivateEvent(TES3::Reference* activator, TES3::Reference* target);
		sol::table createEventTable();

	protected:
		TES3::Reference* m_Activator;
		TES3::Reference* m_Target;
	};
}

#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class ActivationTargetChangedEvent : public ObjectFilteredEvent, public DisableableEvent<ActivationTargetChangedEvent> {
	public:
		ActivationTargetChangedEvent(TES3::Reference* previous, TES3::Reference* current);
		sol::table createEventTable();

	protected:
		TES3::Reference* m_PreviousReference;
		TES3::Reference* m_CurrentReference;
	};
}

#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class VFXCreatedEvent : public ObjectFilteredEvent, public DisableableEvent<VFXCreatedEvent> {
	public:
		VFXCreatedEvent(TES3::VFX* vfx, const char* context);
		sol::table createEventTable();

	protected:
		TES3::VFX* m_VFX;
		const char* m_Context;
	};
}

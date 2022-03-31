#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class ActiveMagicEffectIconsUpdatedEvent : public GenericEvent, public DisableableEvent<ActiveMagicEffectIconsUpdatedEvent> {
	public:
		ActiveMagicEffectIconsUpdatedEvent();
		sol::table createEventTable();
	};
}

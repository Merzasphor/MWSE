#include "LuaActiveMagicEffectIconsUpdatedEvent.h"

#include "LuaManager.h"

namespace mwse::lua::event {
	ActiveMagicEffectIconsUpdatedEvent::ActiveMagicEffectIconsUpdatedEvent() :
		GenericEvent("activeMagicEffectIconsUpdated")
	{

	}

	sol::table ActiveMagicEffectIconsUpdatedEvent::createEventTable() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table eventData = state.create_table();

		return eventData;
	}

	bool ActiveMagicEffectIconsUpdatedEvent::m_EventEnabled = false;
}

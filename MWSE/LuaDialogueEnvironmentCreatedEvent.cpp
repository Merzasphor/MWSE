#include "LuaDialogueEnvironmentCreatedEvent.h"

#include "TES3Reference.h"
#include "TES3Sound.h"

#include "LuaManager.h"

namespace mwse::lua::event {
	DialogueEnvironmentCreatedEvent::DialogueEnvironmentCreatedEvent(sol::environment environment) :
		GenericEvent("dialogueEnvironmentCreated"),
		m_Environment(environment)
	{

	}

	sol::table DialogueEnvironmentCreatedEvent::createEventTable() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table eventData = state.create_table();

		eventData["environment"] = m_Environment;

		return eventData;
	}

	bool DialogueEnvironmentCreatedEvent::m_EventEnabled = false;
}

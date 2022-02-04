#include "LuaDeterminedActionEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3CombatSession.h"
#include "TES3MobileActor.h"
#include "TES3Reference.h"

namespace mwse::lua::event {
	DeterminedActionEvent::DeterminedActionEvent(TES3::CombatSession* session) :
		ObjectFilteredEvent("determinedAction", session->parentActor->reference),
		m_Session(session)
	{

	}

	sol::table DeterminedActionEvent::createEventTable() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table eventData = state.create_table();

		eventData["session"] = m_Session;

		return eventData;
	}

	bool DeterminedActionEvent::m_EventEnabled = false;
}

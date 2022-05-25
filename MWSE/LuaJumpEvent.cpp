#include "LuaJumpEvent.h"

#include "LuaManager.h"

#include "TES3MobileActor.h"
#include "TES3Reference.h"
#include "TES3Vectors.h"

namespace mwse::lua::event {
	JumpEvent::JumpEvent(TES3::MobileActor* mobile, TES3::Vector3& velocity) :
		ObjectFilteredEvent("jump", mobile->reference),
		m_MobileActor(mobile),
		m_Velocity(velocity)
	{

	}

	sol::table JumpEvent::createEventTable() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		auto& state = stateHandle.state;
		auto eventData = state.create_table();
		
		eventData["mobile"] = m_MobileActor;
		eventData["reference"] = m_MobileActor->reference;
		eventData["velocity"] = m_Velocity;

		return eventData;
	}

	bool JumpEvent::m_EventEnabled = false;
}

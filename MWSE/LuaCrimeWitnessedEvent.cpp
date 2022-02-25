#include "LuaCrimeWitnessedEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Actor.h"
#include "TES3CrimeEvent.h"
#include "TES3Faction.h"
#include "TES3MobileActor.h"
#include "TES3Reference.h"

namespace mwse::lua::event {
	CrimeWitnessedEvent::CrimeWitnessedEvent(TES3::MobileActor* witness, TES3::CrimeEvent* crime) :
		GenericEvent("crimeWitnessed"),
		m_Witness(witness),
		m_Crime(crime)
	{

	}

	sol::object CrimeWitnessedEvent::getEventOptions() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table options = state.create_table();
		options["filter"] = m_Crime->typeString.c_str;
		return options;
	}

	sol::table CrimeWitnessedEvent::createEventTable() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table eventData = state.create_table();

		eventData["type"] = m_Crime->typeString.c_str;
		eventData["position"] = m_Crime->position;
		eventData["realTimestamp"] = m_Crime->timestamp;
		if (m_Crime->victimBaseActor) {
			eventData["victim"] = m_Crime->victimBaseActor;
		}
		else {
			eventData["victim"] = m_Crime->victimFaction;
		}
		eventData["victimMobile"] = m_Crime->victim;
		eventData["victimFaction"] = m_Crime->victimFaction;
		eventData["value"] = m_Crime->penalty;
		eventData["witness"] = m_Witness->reference;
		eventData["witnessMobile"] = m_Witness;

		return eventData;
	}

	bool CrimeWitnessedEvent::m_EventEnabled = false;
}

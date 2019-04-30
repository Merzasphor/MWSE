#include "LuaCrimeWitnessedEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3CrimeEvent.h"
#include "TES3MobileActor.h"
#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		namespace event {
			CrimeWitnessedEvent::CrimeWitnessedEvent(TES3::MobileActor * witness, TES3::CrimeEvent * crime) :
				ObjectFilteredEvent("crimeWitnessed", witness->reference ? witness->reference->getBaseObject() : nullptr),
				m_Witness(witness),
				m_Crime(crime)
			{

			}

			sol::table CrimeWitnessedEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["type"] = m_Crime->typeString.c_str;
				eventData["value"] = m_Crime->penalty;
				eventData["witness"] = makeLuaObject(m_Witness->reference);
				eventData["witnessMobile"] = makeLuaObject(m_Witness);

				return eventData;
			}
		}
	}
}

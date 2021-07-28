#include "LuaAbsorbMagicEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Creature.h"
#include "TES3MobileActor.h"
#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		namespace event {
			AbsorbMagicEvent::AbsorbMagicEvent(TES3::MobileActor* actor, TES3::MagicSourceInstance* instance, float absorb) :
				ObjectFilteredEvent("absorbMagic", actor->reference),
				m_MobileActor(actor),
				m_MagicSourceInstance(instance),
				m_Absorb(absorb)
			{

			}

			sol::table AbsorbMagicEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["absorb"] = m_Absorb;
				eventData["mobile"] = m_MobileActor;
				eventData["target"] = m_MobileActor->reference;
				eventData["source"] = m_MagicSourceInstance->sourceCombo.source.asGeneric;
				eventData["sourceInstance"] = m_MagicSourceInstance;

				return eventData;
			}

			bool AbsorbMagicEvent::m_EventEnabled = false;
		}
	}
}

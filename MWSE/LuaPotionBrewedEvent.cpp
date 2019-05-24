#include "LuaPotionBrewedEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Alchemy.h"

namespace mwse {
	namespace lua {
		namespace event {
			PotionBrewedEvent::PotionBrewedEvent(TES3::Alchemy * object) :
				GenericEvent("potionBrewed"),
				m_Object(object)
			{

			}

			sol::table PotionBrewedEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["object"] = makeLuaObject(m_Object);

				return eventData;
			}

			bool PotionBrewedEvent::m_EventEnabled = false;
		}
	}
}

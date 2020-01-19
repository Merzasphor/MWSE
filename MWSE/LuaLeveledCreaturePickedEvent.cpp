#include "LuaLeveledCreaturePickedEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3LeveledList.h"

namespace mwse {
	namespace lua {
		namespace event {
			LeveledCreaturePickedEvent::LeveledCreaturePickedEvent(TES3::LeveledCreature * list, TES3::Object * vanillaResult) :
				ObjectFilteredEvent("leveledCreaturePicked", list),
				m_List(list),
				m_Result(vanillaResult)
			{

			}

			sol::table LeveledCreaturePickedEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["list"] = m_List;
				eventData["pick"] = m_Result;

				return eventData;
			}

			bool LeveledCreaturePickedEvent::m_EventEnabled = false;
		}
	}
}

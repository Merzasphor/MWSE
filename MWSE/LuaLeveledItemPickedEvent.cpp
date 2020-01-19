#include "LuaLeveledItemPickedEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3LeveledList.h"

namespace mwse {
	namespace lua {
		namespace event {
			LeveledItemPickedEvent::LeveledItemPickedEvent(TES3::LeveledItem * list, TES3::Object * vanillaResult) :
				ObjectFilteredEvent("leveledItemPicked", list),
				m_List(list),
				m_Result(vanillaResult)
			{

			}

			sol::table LeveledItemPickedEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["list"] = m_List;
				eventData["pick"] = m_Result;

				return eventData;
			}

			bool LeveledItemPickedEvent::m_EventEnabled = false;
		}
	}
}

#include "LuaInfoGetTextEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3DialogueInfo.h"

namespace mwse {
	namespace lua {
		namespace event {
			InfoGetTextEvent::InfoGetTextEvent(TES3::DialogueInfo * info) :
				ObjectFilteredEvent("infoGetText", info),
				m_DialogueInfo(info)
			{

			}

			sol::table InfoGetTextEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["info"] = m_DialogueInfo;

				return eventData;
			}

			bool InfoGetTextEvent::m_EventEnabled = false;
		}
	}
}

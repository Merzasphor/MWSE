#include "LuaSaveGameEvent.h"

#include "LuaManager.h"

namespace mwse {
	namespace lua {
		namespace event {
			SaveGameEvent::SaveGameEvent(const char* saveName, const char* fileName) :
				GenericEvent("save"),
				m_SaveName(saveName),
				m_FileName(fileName)
			{

			}

			sol::table SaveGameEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["name"] = m_SaveName;
				eventData["filename"] = m_FileName;

				return eventData;
			}

			sol::object SaveGameEvent::getEventOptions() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table options = state.create_table();

				options["filter"] = m_FileName;

				return options;
			}
		}
	}
}

#include "LuaBookGetTextEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Book.h"

namespace mwse {
	namespace lua {
		namespace event {
			BookGetTextEvent::BookGetTextEvent(TES3::Book * info) :
				ObjectFilteredEvent("bookGetText", info),
				m_Book(info)
			{

			}

			sol::table BookGetTextEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["book"] = makeLuaObject(m_Book);

				return eventData;
			}
		}
	}
}

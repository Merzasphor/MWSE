#include "LuaObjectFilteredEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

namespace mwse {
	namespace lua {
		namespace event {
			ObjectFilteredEvent::ObjectFilteredEvent(const char* name, TES3::BaseObject* filter) :
				GenericEvent(name),
				m_EventFilter(filter)
			{

			}

			sol::object ObjectFilteredEvent::getEventOptions() {
				sol::table options = LuaManager::getInstance().getState().create_table();
				options["filter"] = makeLuaObject(m_EventFilter);
				return options;
			}
		}
	}
}

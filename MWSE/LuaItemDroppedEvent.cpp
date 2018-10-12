#include "LuaItemDroppedEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		namespace event {
			ItemDroppedEvent::ItemDroppedEvent(TES3::Reference * reference) :
				ObjectFilteredEvent("itemDropped", reference->baseObject),
				m_Reference(reference)
			{

			}

			sol::table ItemDroppedEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["reference"] = makeLuaObject(m_Reference);

				return eventData;
			}
		}
	}
}

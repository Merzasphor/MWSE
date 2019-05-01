#include "LuaReferenceSceneNodeCreatedEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		namespace event {
			ReferenceSceneNodeCreatedEvent::ReferenceSceneNodeCreatedEvent(TES3::Reference* reference) :
				ObjectFilteredEvent("referenceSceneNodeCreated", reference->baseObject),
				m_Reference(reference)
			{

			}

			sol::table ReferenceSceneNodeCreatedEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["reference"] = makeLuaObject(m_Reference);

				return eventData;
			}
		}
	}
}

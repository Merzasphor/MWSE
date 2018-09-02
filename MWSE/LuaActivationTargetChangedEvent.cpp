#include "LuaActivationTargetChangedEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		namespace event {
			ActivationTargetChangedEvent::ActivationTargetChangedEvent(TES3::Reference* previous, TES3::Reference* current) :
				ObjectFilteredEvent("activationTargetChanged", current),
				m_PreviousReference(previous),
				m_CurrentReference(current)
			{

			}

			sol::table ActivationTargetChangedEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["previous"] = makeLuaObject(m_PreviousReference);
				eventData["current"] = makeLuaObject(m_CurrentReference);

				return eventData;
			}
		}
	}
}

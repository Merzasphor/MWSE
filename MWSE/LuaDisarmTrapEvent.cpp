#include "LuaDisarmTrapEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3ItemData.h"
#include "TES3Reference.h"
#include "TES3MobileNPC.h"

namespace mwse {
	namespace lua {
		namespace event {
			DisarmTrapEvent::DisarmTrapEvent(TES3::Reference * reference, TES3::LockAttachmentNode * lockData, TES3::MobileNPC * disarmer, TES3::Item * tool, TES3::ItemData * itemData, float chance) :
				ObjectFilteredEvent("trapDisarm", reference->baseObject),
				m_Reference(reference),
				m_LockData(lockData),
				m_Disarmer(disarmer),
				m_Tool(tool),
				m_ItemData(itemData),
				m_Chance(chance)
			{

			}

			sol::table DisarmTrapEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["reference"] = makeLuaObject(m_Reference);
				eventData["lockData"] = m_LockData;

				eventData["disarmer"] = makeLuaObject(m_Disarmer);

				eventData["tool"] = makeLuaObject(m_Tool);
				eventData["toolItemData"] = m_ItemData;

				eventData["chance"] = m_Chance;

				return eventData;
			}

			bool DisarmTrapEvent::m_EventEnabled = false;
		}
	}
}

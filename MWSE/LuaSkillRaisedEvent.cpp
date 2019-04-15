#include "LuaSkillRaisedEvent.h"

#include "LuaManager.h"

namespace mwse {
	namespace lua {
		namespace event {
			SkillRaisedEvent::SkillRaisedEvent(int skillId, float newLevel) :
				GenericEvent("skillRaised"),
				m_Skill(skillId),
				m_NewLevel(newLevel)
			{

			}

			sol::table SkillRaisedEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["skill"] = m_Skill;
				eventData["level"] = m_NewLevel;

				return eventData;
			}

			sol::object SkillRaisedEvent::getEventOptions() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table options = state.create_table();

				options["filter"] = m_Skill;

				return options;
			}
		}
	}
}

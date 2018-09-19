#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class SkillRaisedEvent : public GenericEvent {
			public:
				SkillRaisedEvent(int skillId, float newLevel);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				int m_Skill;
				float m_NewLevel;
			};
		}
	}
}

#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class SkillExerciseEvent : public GenericEvent {
			public:
				SkillExerciseEvent(int skillId, float progress);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				int m_Skill;
				float m_Progress;
			};
		}
	}
}

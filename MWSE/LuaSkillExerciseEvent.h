#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class SkillExerciseEvent : public GenericEvent, public DisableableEvent<SkillExerciseEvent> {
	public:
		SkillExerciseEvent(int skillId, float progress);
		sol::table createEventTable();
		sol::object getEventOptions();

	protected:
		int m_Skill;
		float m_Progress;
	};
}

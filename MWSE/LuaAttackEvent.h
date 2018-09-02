#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class AttackEvent : public ObjectFilteredEvent {
			public:
				AttackEvent(TES3::ActorAnimationData* animData);
				sol::table createEventTable();

			protected:
				TES3::ActorAnimationData* m_AnimationData;
			};
		}
	}
}

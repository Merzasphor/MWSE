#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Vectors.h"

namespace mwse::lua::event {
	class JumpEvent : public ObjectFilteredEvent, public DisableableEvent<JumpEvent> {
	public:
		JumpEvent(TES3::MobileActor* mobile, TES3::Vector3& velocity);
		sol::table createEventTable();

	protected:
		TES3::MobileActor* m_MobileActor;
		TES3::Vector3 m_Velocity;
	};
}

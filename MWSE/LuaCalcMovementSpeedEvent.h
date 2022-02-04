#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CalculateMovementSpeed : public ObjectFilteredEvent, public DisableableEvent<CalculateMovementSpeed> {
	public:
		enum MovementType {
			Move,
			Walk,
			Run,
			Swim,
			SwimRun,
			Fly
		};

		CalculateMovementSpeed(MovementType type, TES3::MobileActor* mobile, float speed);
		sol::table createEventTable();

	protected:
		MovementType m_Type;
		TES3::MobileActor* m_MobileActor;
		float m_Speed;
	};
}

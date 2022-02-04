#pragma once

#include "TES3WeatherController.h"

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CalcSunDamageScalarEvent : public GenericEvent, public DisableableEvent<CalcSunDamageScalarEvent> {
	public:
		CalcSunDamageScalarEvent(float damage);
		sol::table createEventTable();

	protected:
		float m_Damage;
	};
}
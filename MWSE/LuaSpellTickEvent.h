#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Defines.h"

namespace mwse::lua::event {
	class SpellTickEvent : public GenericEvent, public DisableableEvent<SpellTickEvent> {
	public:
		SpellTickEvent(int effectId, TES3::MagicSourceInstance* sourceInstance, float deltaTime, TES3::MagicEffectInstance* effectInstance, int effectIndex);
		sol::table createEventTable();
		sol::object getEventOptions();

	protected:
		int m_EffectId;
		TES3::MagicSourceInstance* m_SourceInstance;
		float m_DeltaTime;
		TES3::MagicEffectInstance* m_EffectInstance;
		int m_EffectIndex;
	};
}

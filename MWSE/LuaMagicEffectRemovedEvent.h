#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class MagicEffectRemovedEvent : public ObjectFilteredEvent, public DisableableEvent<MagicEffectRemovedEvent> {
	public:
		MagicEffectRemovedEvent(TES3::MobileActor* mobileActor, TES3::MagicSourceInstance* magicSourceInstance, int effectIndex);
		sol::table createEventTable();

	protected:
		TES3::MobileActor* m_MobileActor;
		TES3::MagicSourceInstance* m_MagicSourceInstance;
		int m_EffectIndex;
	};
}
#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class FilterSoulGemTargetEvent : public ObjectFilteredEvent, public DisableableEvent<FilterSoulGemTargetEvent> {
	public:
		FilterSoulGemTargetEvent(TES3::Misc* soulGem, TES3::MobileActor* target);
		sol::table createEventTable();

	protected:
		TES3::Misc* m_SoulGem;
		TES3::MobileActor* m_Target;
	};
}

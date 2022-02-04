#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Armor.h"

namespace mwse::lua::event {
	class CalcHitArmorPiece : public ObjectFilteredEvent, public DisableableEvent<CalcHitArmorPiece> {
	public:
		CalcHitArmorPiece(TES3::MobileNPC* actor, TES3::ArmorSlot::ArmorSlot slot, TES3::ArmorSlot::ArmorSlot fallback);
		sol::table createEventTable();

	protected:
		TES3::MobileNPC* m_Mobile;
		TES3::ArmorSlot::ArmorSlot m_Slot;
		TES3::ArmorSlot::ArmorSlot m_Fallback;
	};
}

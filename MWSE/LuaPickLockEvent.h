#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class PickLockEvent : public ObjectFilteredEvent, public DisableableEvent<PickLockEvent> {
	public:
		PickLockEvent(TES3::Reference* reference, TES3::LockAttachmentNode* lockData, TES3::MobileNPC* picker, TES3::Item* tool, TES3::ItemData* itemData, float chance, bool lockPresent);
		sol::table createEventTable();

	protected:
		TES3::Reference* m_Reference;
		TES3::LockAttachmentNode* m_LockData;
		TES3::MobileNPC* m_Picker;
		TES3::Item* m_Tool;
		TES3::ItemData* m_ItemData;
		float m_Chance;
		bool m_LockPresent;
	};
}

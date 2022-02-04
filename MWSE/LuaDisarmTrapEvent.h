#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class DisarmTrapEvent : public ObjectFilteredEvent, public DisableableEvent<DisarmTrapEvent> {
	public:
		DisarmTrapEvent(TES3::Reference* reference, TES3::LockAttachmentNode* lockData, TES3::MobileNPC* disarmer, TES3::Item* tool, TES3::ItemData* itemData, float chance, bool trapPresent);
		sol::table createEventTable();

	protected:
		TES3::Reference* m_Reference;
		TES3::LockAttachmentNode* m_LockData;
		TES3::MobileNPC* m_Disarmer;
		TES3::Item* m_Tool;
		TES3::ItemData* m_ItemData;
		float m_Chance;
		bool m_TrapPresent;
	};
}

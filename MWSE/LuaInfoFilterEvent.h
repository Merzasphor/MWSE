#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class InfoFilterEvent : public ObjectFilteredEvent, public DisableableEvent<InfoFilterEvent> {
	public:
		InfoFilterEvent(TES3::DialogueInfo* info, TES3::Object* actor, TES3::Reference* reference, int flag, TES3::Dialogue* dialogue, bool passes);
		sol::table createEventTable();

	protected:
		TES3::DialogueInfo* m_DialogueInfo;
		TES3::Object* m_Actor;
		TES3::Reference* m_Reference;
		int m_Source;
		TES3::Dialogue* m_Dialogue;
		bool m_Passes;
	};
}

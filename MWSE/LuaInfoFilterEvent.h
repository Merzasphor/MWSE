#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class InfoFilterEvent : public ObjectFilteredEvent {
			public:
				InfoFilterEvent(TES3::DialogueInfo * info, TES3::Actor * actor, TES3::Reference * reference, signed char flag, TES3::Dialogue * dialogue, bool passes);
				sol::table createEventTable();

			protected:
				TES3::DialogueInfo* m_DialogueInfo;
				TES3::Actor* m_Actor;
				TES3::Reference* m_Reference;
				signed char m_Source;
				TES3::Dialogue* m_Dialogue;
				bool m_Passes;
			};
		}
	}
}

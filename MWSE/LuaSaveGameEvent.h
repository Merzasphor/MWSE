#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class SaveGameEvent : public GenericEvent {
			public:
				SaveGameEvent(const char* saveName, const char* fileName);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				const char* m_SaveName;
				const char* m_FileName;
			};
		}
	}
}

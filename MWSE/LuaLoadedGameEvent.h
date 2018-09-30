#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class LoadedGameEvent : public GenericEvent {
			public:
				LoadedGameEvent(const char* fileName, bool quickLoad = false, bool newGame = false);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				const char* m_FileName;
				bool m_QuickLoad;
				bool m_NewGame;
			};
		}
	}
}

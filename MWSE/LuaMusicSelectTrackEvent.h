#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class MusicSelectTrackEvent : public GenericEvent {
			public:
				MusicSelectTrackEvent(int situation);
				sol::table createEventTable();

			protected:
				int m_Situation;
			};
		}
	}
}

#pragma once

#include "LuaSaveGameEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class SavedGameEvent : public SaveGameEvent {
			public:
				SavedGameEvent(const char* saveName, const char* fileName);
			};
		}
	}
}

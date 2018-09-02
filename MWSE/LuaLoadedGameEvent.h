#pragma once

#include "LuaLoadGameEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class LoadedGameEvent : public LoadGameEvent {
			public:
				LoadedGameEvent(const char* fileName, bool quickLoad = false, bool newGame = false);
			};
		}
	}
}

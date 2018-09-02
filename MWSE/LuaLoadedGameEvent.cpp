#include "LuaLoadedGameEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			LoadedGameEvent::LoadedGameEvent(const char* fileName, bool quickLoad, bool newGame) :
				LoadGameEvent(fileName, quickLoad, newGame)
			{
				m_EventName = "loaded";
			}
		}
	}
}

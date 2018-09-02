#include "LuaSavedGameEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			SavedGameEvent::SavedGameEvent(const char* saveName, const char* fileName) :
				SaveGameEvent(saveName, fileName)
			{
				m_EventName = "saved";
			}
		}
	}
}

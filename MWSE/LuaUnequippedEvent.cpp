#include "LuaUnequippedEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			UnequippedEvent::UnequippedEvent(TES3::Actor* a, TES3::MobileActor* ma, TES3::BaseObject* i, TES3::ItemData* id) :
				EquippedEvent(a, ma, i, id)
			{
				m_EventName = "unequipped";
			}
		}
	}
}

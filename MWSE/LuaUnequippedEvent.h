#pragma once

#include "LuaEquippedEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			// Unequipped event. Same as the equipped event with a different name.
			class UnequippedEvent : public EquippedEvent {
			public:
				UnequippedEvent(TES3::Actor* a, TES3::MobileActor* ma, TES3::BaseObject* i, TES3::ItemData* id);
			};
		}
	}
}

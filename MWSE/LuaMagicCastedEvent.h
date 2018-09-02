#pragma once

#include "LuaGenericEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			class MagicCastedEvent : public GenericEvent {
			public:
				MagicCastedEvent(TES3::MagicSourceInstance* magicInstance);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				TES3::MagicSourceInstance* m_MagicSourceInstance;
			};
		}
	}
}

#pragma once

#include "LuaGenericEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			class SpellCastedEvent : public GenericEvent {
			public:
				SpellCastedEvent(TES3::MagicSourceInstance* magicInstance, bool success, int expGainSchool);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				TES3::MagicSourceInstance* m_MagicSourceInstance;
				int m_ExpGainSchool;
			};
		}
	}
}

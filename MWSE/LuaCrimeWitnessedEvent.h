#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CrimeWitnessedEvent : public GenericEvent {
			public:
				CrimeWitnessedEvent(TES3::MobileActor * witness, TES3::CrimeEvent * crime);
				sol::object getEventOptions();
				sol::table createEventTable();

			protected:
				TES3::MobileActor * m_Witness;
				TES3::CrimeEvent * m_Crime;
			};
		}
	}
}

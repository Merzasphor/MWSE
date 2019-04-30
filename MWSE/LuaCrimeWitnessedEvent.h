#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CrimeWitnessedEvent : public ObjectFilteredEvent {
			public:
				CrimeWitnessedEvent(TES3::MobileActor * witness, TES3::CrimeEvent * crime);
				sol::table createEventTable();

			protected:
				TES3::MobileActor * m_Witness;
				TES3::CrimeEvent * m_Crime;
			};
		}
	}
}

#pragma once

#include "LuaGenericEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			class SpellCastEvent : public GenericEvent {
			public:
				SpellCastEvent(TES3::Spell* spell, TES3::MobileActor* caster, float castChance, int weakestSchool);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				TES3::Spell* m_Spell;
				TES3::MobileActor* m_Caster;
				float m_CastChance;
				int m_WeakestSchool;
			};
		}
	}
}

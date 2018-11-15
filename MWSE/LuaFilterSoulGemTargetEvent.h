#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class FilterSoulGemTargetEvent : public ObjectFilteredEvent {
			public:
				FilterSoulGemTargetEvent(TES3::Misc * soulGem, TES3::MobileActor * target);
				sol::table createEventTable();

			protected:
				TES3::Misc * m_SoulGem;
				TES3::MobileActor * m_Target;
			};
		}
	}
}

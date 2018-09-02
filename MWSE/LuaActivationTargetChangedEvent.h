#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class ActivationTargetChangedEvent : public ObjectFilteredEvent {
			public:
				ActivationTargetChangedEvent(TES3::Reference* previous, TES3::Reference* current);
				sol::table createEventTable();

			protected:
				TES3::Reference* m_PreviousReference;
				TES3::Reference* m_CurrentReference;
			};
		}
	}
}

#pragma once

#include "LuaGenericEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			class UiRefreshedEvent : public GenericEvent {
			public:
				UiRefreshedEvent(TES3::UI::Element * element);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				TES3::UI::Element * m_Element;
			};
		}
	}
}

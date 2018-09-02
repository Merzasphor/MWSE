#pragma once

#include "LuaGenericEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			class GenericUiActivatedEvent : public GenericEvent {
			public:
				GenericUiActivatedEvent(TES3::UI::Element * parent);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				TES3::UI::Element* m_Element;
				bool m_Created;
			};

			// TODO: Remove deprecated event.
			class GenericUiCreatedEvent : public GenericUiActivatedEvent {
			public:
				GenericUiCreatedEvent(TES3::UI::Element * parent);
			};
		}
	}
}

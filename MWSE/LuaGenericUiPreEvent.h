#pragma once

#include "LuaGenericEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			class GenericUiPreEvent : public GenericEvent {
			public:
				GenericUiPreEvent(TES3::UI::Element* parent, TES3::UI::Element* element, unsigned int prop, unsigned int var1, unsigned int var2);
				sol::table createEventTable();

			protected:
				TES3::UI::Element* m_Parent;
				TES3::UI::Element* m_Source;
				unsigned int m_Property;
				unsigned int m_Variable1;
				unsigned int m_Variable2;
			};
		}
	}
}

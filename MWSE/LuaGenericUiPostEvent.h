#pragma once

#include "LuaGenericUiPreEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class GenericUiPostEvent : public GenericUiPreEvent {
			public:
				GenericUiPostEvent(TES3::UI::Element* parent, TES3::UI::Element* element, unsigned int prop, unsigned int var1, unsigned int var2);
			};
		}
	}
}

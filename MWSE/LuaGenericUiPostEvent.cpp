#include "LuaGenericUiPostEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			GenericUiPostEvent::GenericUiPostEvent(TES3::UI::Element* parent, TES3::UI::Element* source, unsigned int prop, unsigned int var1, unsigned int var2) :
				GenericUiPreEvent(parent, source, prop, var1, var2)
			{
				m_EventName = "uiEvent";
			}
		}
	}
}

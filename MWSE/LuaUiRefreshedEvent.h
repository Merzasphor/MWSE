#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Defines.h"

namespace mwse::lua::event {
	class UiRefreshedEvent : public GenericEvent, public DisableableEvent<UiRefreshedEvent> {
	public:
		UiRefreshedEvent(TES3::UI::Element* element);
		sol::table createEventTable();
		sol::object getEventOptions();

	protected:
		TES3::UI::Element* m_Element;
	};
}

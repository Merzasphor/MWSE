#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class ButtonPressedEvent : public GenericEvent, public DisableableEvent<ButtonPressedEvent> {
	public:
		ButtonPressedEvent(int buttonId);
		sol::table createEventTable();

	protected:
		int m_ButtonId;
	};
}

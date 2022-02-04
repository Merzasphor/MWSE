#pragma once

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

#include "TES3Defines.h"

namespace mwse::lua::event {
	class AddTopicEvent : public GenericEvent, public DisableableEvent<AddTopicEvent> {
	public:
		AddTopicEvent(TES3::Dialogue* topic);
		sol::table createEventTable();

	protected:
		TES3::Dialogue* m_Topic;
	};
}

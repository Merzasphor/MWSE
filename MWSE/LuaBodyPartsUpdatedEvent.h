#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	// BodyPartsUpdatedEvent event. Called after an actor updates its body part models.
	class BodyPartsUpdatedEvent : public GenericEvent, public DisableableEvent<BodyPartsUpdatedEvent> {
	public:
		BodyPartsUpdatedEvent(TES3::Reference* reference, TES3::MobileActor* actor);
		sol::table createEventTable();

	protected:
		TES3::Reference* m_Reference;
		TES3::MobileActor* m_MobileActor;
	};
}

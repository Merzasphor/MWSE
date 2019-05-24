#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class ConvertReferenceToItemEvent : public ObjectFilteredEvent, public DisableableEvent<ConvertReferenceToItemEvent> {
			public:
				ConvertReferenceToItemEvent(TES3::Reference * reference);
				sol::table createEventTable();

			protected:
				TES3::Reference * m_Reference;
			};
		}
	}
}

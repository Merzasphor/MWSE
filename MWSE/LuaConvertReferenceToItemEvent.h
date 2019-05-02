#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class ConvertReferenceToItemEvent : public ObjectFilteredEvent {
			public:
				ConvertReferenceToItemEvent(TES3::Reference * reference);
				sol::table createEventTable();

			protected:
				TES3::Reference * m_Reference;
			};
		}
	}
}

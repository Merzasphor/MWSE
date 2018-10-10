#pragma once

#include "LuaObjectFilteredEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class BookGetTextEvent : public ObjectFilteredEvent {
			public:
				BookGetTextEvent(TES3::Book * book);
				sol::table createEventTable();

			protected:
				TES3::Book* m_Book;
			};
		}
	}
}

#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class BookGetTextEvent : public ObjectFilteredEvent, public DisableableEvent<BookGetTextEvent> {
	public:
		BookGetTextEvent(TES3::Book* book);
		sol::table createEventTable();

	protected:
		TES3::Book* m_Book;
	};
}

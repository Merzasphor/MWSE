#pragma once

#include "LuaGenericEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CalcRestInterruptEvent : public GenericEvent {
			public:
				CalcRestInterruptEvent(int count, int hour);
				sol::table createEventTable();

			protected:
				int m_Count;
				int m_Hour;
			};
		}
	}
}

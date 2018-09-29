#pragma once

#include "LuaGenericEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			class FilterInventorySelectEvent : public GenericEvent {
			public:
				FilterInventorySelectEvent(const char * type, TES3::Item * item, TES3::ItemData * itemData);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				const char* m_Type;
				TES3::Item* m_Item;
				TES3::ItemData* m_ItemData;
			};
		}
	}
}

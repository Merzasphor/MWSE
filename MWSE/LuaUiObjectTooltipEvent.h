#pragma once

#include "LuaGenericEvent.h"

#include "TES3Defines.h"

namespace mwse {
	namespace lua {
		namespace event {
			class UiObjectTooltipEvent : public GenericEvent {
			public:
				UiObjectTooltipEvent(TES3::UI::Element* tooltip, TES3::Object* object, TES3::ItemData* itemData, int count);
				sol::table createEventTable();

			protected:
				TES3::UI::Element* m_Tooltip;
				TES3::Object* m_Object;
				TES3::ItemData* m_ItemData;
				int m_Count;
			};
		}
	}
}

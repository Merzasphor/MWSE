#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class BarterOfferEvent : public GenericEvent, public DisableableEvent<BarterOfferEvent> {
			public:
				BarterOfferEvent(TES3::MobileActor* mobileActor, bool success, int sale, int offer);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_MobileActor;
				bool m_Success;
				int m_Sale;
				int m_Offer;
			};
		}
	}
}
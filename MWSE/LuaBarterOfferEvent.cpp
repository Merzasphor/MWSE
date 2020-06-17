#include "LuaBarterOfferEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3MobileActor.h"
#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		namespace event {
			BarterOfferEvent::BarterOfferEvent(TES3::MobileActor* mobileActor, bool success) :
				GenericEvent("barterOffer"),
				m_MobileActor(mobileActor),
				m_Success(success)
			{

			}

			sol::table BarterOfferEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["mobile"] = m_MobileActor;
				eventData["success"] = m_Success;

				return eventData;
			}

			bool BarterOfferEvent::m_EventEnabled = false;
		}
	}
}

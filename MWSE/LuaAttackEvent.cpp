#include "LuaAttackEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3ActorAnimationData.h"
#include "TES3MobileActor.h"
#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		namespace event {
			AttackEvent::AttackEvent(TES3::ActorAnimationData* animData) :
				ObjectFilteredEvent("attack", animData->mobileActor->reference),
				m_AnimationData(animData)
			{

			}

			sol::table AttackEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["mobile"] = m_AnimationData->mobileActor;
				eventData["reference"] = m_AnimationData->mobileActor->reference;

				TES3::MobileActor* target = m_AnimationData->mobileActor->actionData.hitTarget;
				if (target) {
					eventData["targetMobile"] = target;
					eventData["targetReference"] = target->reference;
				}

				return eventData;
			}

			bool AttackEvent::m_EventEnabled = false;
		}
	}
}

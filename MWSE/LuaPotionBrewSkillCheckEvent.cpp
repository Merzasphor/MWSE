#include "LuaPotionBrewSkillCheckEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Alchemy.h"
#include "TES3Apparatus.h"
#include "TES3Ingredient.h"
#include "TES3MobilePlayer.h"
#include "TES3WorldController.h"

namespace mwse {
	namespace lua {
		namespace event {
			PotionBrewSkillCheckEvent::PotionBrewSkillCheckEvent(float potionStrength) :
				GenericEvent("potionBrewSkillCheck"),
				m_PotionStrength(potionStrength)
			{

			}

			sol::table PotionBrewSkillCheckEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["potionStrength"] = m_PotionStrength;
				eventData["success"] = m_PotionStrength >= 0;

				auto macp = TES3::WorldController::get()->getMobilePlayer();
				eventData["alembic"] = macp->lastUsedAlembic;
				eventData["calcinator"] = macp->lastUsedCalcinator;
				eventData["mortar"] = macp->lastUsedMortar;
				eventData["retort"] = macp->lastUsedRetort;

				return eventData;
			}

			bool PotionBrewSkillCheckEvent::m_EventEnabled = false;
		}
	}
}

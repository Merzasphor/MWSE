#include "TES3MobileNPC.h"

#include "LuaManager.h"

#include "LuaCalcMovementSpeedEvent.h"

#include "TES3Class.h"
#include "TES3DataHandler.h"
#include "TES3GameSetting.h"
#include "TES3NPC.h"

#define TES3_MobileNPC_calcWalkSpeed 0x526F70

namespace TES3 {
	float MobileNPC::calculateWalkSpeed() {
		// Call the original function to get the default walk value.
		float speed = reinterpret_cast<float(__thiscall *)(MobileNPC*)>(TES3_MobileNPC_calcWalkSpeed)(this);

		// Launch our event, and overwrite the speed with what was given back to us.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::CalculateMovementSpeed(mwse::lua::event::CalculateMovementSpeed::Walk, this, speed));
		if (eventData.valid()) {
			speed = eventData["speed"];
		}

		return speed;
	}

	float MobileNPC::getSkillRequirement(int skillId) {
		const SkillStatistic& skill = skills[skillId];

		DataHandler* dataHandler = DataHandler::get();
		GameSetting ** gmsts = dataHandler->nonDynamicData->GMSTs;

		// Multiply requirement by skill type bonus.
		float requirement = skill.base + 1.0f;
		if (skill.type == SkillType::Misc) {
			requirement *= gmsts[GMST::fMiscSkillBonus]->value.asFloat;
		}
		else if (skill.type == SkillType::Minor) {
			requirement *= gmsts[GMST::fMinorSkillBonus]->value.asFloat;
		}
		else if (skill.type == SkillType::Major) {
			requirement *= gmsts[GMST::fMajorSkillBonus]->value.asFloat;
		}

		// Multiply requirement by specialization bonus.
		Class* classRecord = npcInstance->getClass();
		if (dataHandler->nonDynamicData->skills[skillId].specialization == classRecord->specialization) {
			requirement *= gmsts[GMST::fSpecialSkillBonus]->value.asFloat;
		}

		return requirement;
	}
}

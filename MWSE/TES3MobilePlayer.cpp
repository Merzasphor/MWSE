#include "TES3MobilePlayer.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "LuaDeathEvent.h"
#include "LuaSkillExerciseEvent.h"

#include "Log.h"

#include "TES3Skill.h"
#include "TES3PlayerAnimationData.h"

#define TES3_MobilePlayer_exerciseSkill 0x56A5D0
#define TES3_MobilePlayer_levelSkill 0x56BBE0
#define TES3_MobilePlayer_getGoldHeld 0x52B450
#define TES3_MobilePlayer_onDeath 0x56A120
#define TES3_MobilePlayer_getBounty 0x5688B0
#define TES3_MobilePlayer_setBounty 0x5688D0
#define TES3_MobilePlayer_modBounty 0x5688F0

namespace TES3 {
	void MobilePlayer::exerciseSkill(int skillId, float progress) {
		// Invoke our combat start event and check if it is blocked.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::SkillExerciseEvent(skillId, progress));
		if (eventData.valid()) {
			if (eventData["block"] == true) {
				return;
			}

			skillId = eventData["skill"];
			progress = eventData["progress"];

			if (skillId < SkillID::FirstSkill || skillId > SkillID::LastSkill) {
				mwse::log::getLog() << "Error: Attempted to exercise skill with id of " << skillId << "." << std::endl;
				return;
			}
		}

		reinterpret_cast<void(__thiscall *)(MobilePlayer*, int, float)>(TES3_MobilePlayer_exerciseSkill)(this, skillId, progress);
	}

	void MobilePlayer::levelSkill(int skillId) {
		reinterpret_cast<void(__thiscall *)(MobilePlayer*, int)>(TES3_MobilePlayer_levelSkill)(this, skillId);
	}

	void MobilePlayer::onDeath() {
		reinterpret_cast<void(__thiscall *)(MobileActor*)>(TES3_MobilePlayer_onDeath)(this);

		// Trigger death event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::DeathEvent(this));
	}

	bool MobilePlayer::is3rdPerson() {
		return vTable.mobileActor->is3rdPerson(this);
	}

	int MobilePlayer::getGold() {
		return reinterpret_cast<int(__thiscall *)(MobilePlayer*)>(TES3_MobilePlayer_getGoldHeld)(this);
	}

	int MobilePlayer::getBounty() {
		return reinterpret_cast<int(__thiscall *)(MobilePlayer*)>(TES3_MobilePlayer_getBounty)(this);
	}

	void MobilePlayer::setBounty(int value) {
		reinterpret_cast<void(__thiscall *)(MobilePlayer*, int)>(TES3_MobilePlayer_setBounty)(this, value);
	}

	void MobilePlayer::modBounty(int delta) {
		reinterpret_cast<void(__thiscall *)(MobilePlayer*, int)>(TES3_MobilePlayer_modBounty)(this, delta);
	}
}

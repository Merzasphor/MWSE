#include "TES3MobilePlayer.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"
#include "LuaUtil.h"

#define TES3_MobilePlayer_exerciseSkill 0x56A5D0
#define TES3_MobilePlayer_levelSkill 0x56BBE0
#define TES3_MobilePlayer_onDeath 0x56A120

namespace TES3 {
	void MobilePlayer::exerciseSkill(int skillId, float progress) {
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
}

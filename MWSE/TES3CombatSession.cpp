#include "TES3CombatSession.h"

#include "LuaManager.h"

#include "LuaDetermineActionEvent.h"
#include "LuaDeterminedActionEvent.h"

namespace TES3 {
	const auto TES3_CombatSession_determineNextAction = reinterpret_cast<void (__thiscall*)(CombatSession*)>(0x538F00);

	void CombatSession::determineNextAction() {
		sol::table result = mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::DetermineActionEvent(this));
		if (result.valid() && result["block"] == true) {
			mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::DeterminedActionEvent(this));
			return;
		}

		TES3_CombatSession_determineNextAction(this);
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::DeterminedActionEvent(this));
	}
}

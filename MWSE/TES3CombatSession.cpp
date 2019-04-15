#include "TES3CombatSession.h"

#include "LuaManager.h"

#include "LuaDetermineActionEvent.h"
#include "LuaDeterminedActionEvent.h"

namespace TES3 {
	const auto TES3_CombatSession_chooseAlchemyWithEffect = reinterpret_cast<float(__thiscall*)(CombatSession*, short)>(0x538330);
	float CombatSession::chooseAlchemyWithEffect(short id) {
		return TES3_CombatSession_chooseAlchemyWithEffect(this, id);
	}

	const auto TES3_CombatSession_determineNextAction = reinterpret_cast<void (__thiscall*)(CombatSession*)>(0x538F00);
	void CombatSession::determineNextAction() {
		auto& luaManager = mwse::lua::LuaManager::getInstance();
		auto stateHandle = luaManager.getThreadSafeStateHandle();
		sol::table result = stateHandle.triggerEvent(new mwse::lua::event::DetermineActionEvent(this));
		if (result.valid() && result["block"] == true) {
			stateHandle.triggerEvent(new mwse::lua::event::DeterminedActionEvent(this));
			return;
		}

		TES3_CombatSession_determineNextAction(this);
		stateHandle.triggerEvent(new mwse::lua::event::DeterminedActionEvent(this));
	}
}

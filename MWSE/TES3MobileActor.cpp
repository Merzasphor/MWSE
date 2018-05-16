#include "TES3MobileActor.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"
#include "LuaUtil.h"

#define TES3_MobileActor_getCell 0x521630
#define TES3_MobileActor_startCombat 0x530470
#define TES3_MobileActor_stopCombat 0x558720
#define TES3_MobileActor_onDeath 0x523AA0

namespace TES3 {
	Cell* MobileActor::getCell() {
		return reinterpret_cast<Cell*(__thiscall *)(MobileActor*)>(TES3_MobileActor_getCell)(this);
	}

	void MobileActor::startCombat(MobileActor* target) {
		// Invoke our combat start event and check if it is blocked.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::CombatStartEvent(this, target));
		if (eventData.valid() && eventData["block"] == true) {
			return;
		}

		// Call original function.
		reinterpret_cast<void(__thiscall *)(MobileActor*, MobileActor*)>(TES3_MobileActor_startCombat)(this, target);

		// Do our follow up started event.
		luaManager.triggerEvent(new mwse::lua::CombatStartedEvent(this, target));
	}

	void MobileActor::stopCombat(bool something) {
		// Invoke our combat stop event and check if it is blocked.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::CombatStopEvent(this));
		if (eventData.valid() && eventData["block"] == true) {
			return;
		}

		// Call original function.
		reinterpret_cast<void(__thiscall *)(MobileActor*, bool)>(TES3_MobileActor_stopCombat)(this, something);

		// Do our follow up stopped event.
		luaManager.triggerEvent(new mwse::lua::CombatStoppedEvent(this));
	}

	void MobileActor::onDeath() {
		reinterpret_cast<void(__thiscall *)(MobileActor*)>(TES3_MobileActor_onDeath)(this);

		// Trigger death event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::DeathEvent(this));
	}

	bool MobileActor::getMobileActorFlag(unsigned int flag) {
		return (actorFlags & flag) != 0;
	}

	void MobileActor::setMobileActorFlag(unsigned int flag, bool set) {
		if (set) {
			actorFlags |= flag;
		}
		else {
			actorFlags &= ~flag;
		}
	}
}

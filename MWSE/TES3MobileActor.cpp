#include "TES3MobileActor.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"
#include "LuaUtil.h"

#define TES3_MobileActor_getCell 0x521630
#define TES3_MobileActor_startCombat 0x530470
#define TES3_MobileActor_stopCombat 0x558720

namespace TES3 {
	Cell* MobileActor::getCell() {
		return reinterpret_cast<Cell*(__thiscall *)(MobileActor*)>(TES3_MobileActor_getCell)(this);
	}

	void MobileActor::startCombat(MobileActor* target) {
		// Prepare our event data.
		sol::state& state = mwse::lua::LuaManager::getInstance().getState();
		sol::table eventData = state.create_table();
		eventData["actor"] = mwse::lua::makeLuaObject(this);
		eventData["target"] = mwse::lua::makeLuaObject(target);

		// If our event data says to block, don't let the object activate.
		mwse::lua::event::trigger("combatStart", eventData);
		if (eventData["block"] == true) {
			return;
		}

		reinterpret_cast<void(__thiscall *)(MobileActor*, MobileActor*)>(TES3_MobileActor_startCombat)(this, target);

		// Prepare our event data.
		eventData = state.create_table();
		eventData["actor"] = mwse::lua::makeLuaObject(this);
		eventData["target"] = mwse::lua::makeLuaObject(target);

		// If our event data says to block, don't let the object activate.
		mwse::lua::event::trigger("combatStarted", eventData);
	}

	void MobileActor::stopCombat(bool something) {
		// Prepare our event data.
		sol::state& state = mwse::lua::LuaManager::getInstance().getState();
		sol::table eventData = state.create_table();
		eventData["actor"] = mwse::lua::makeLuaObject(this);

		// If our event data says to block, don't let the object activate.
		mwse::lua::event::trigger("combatStop", eventData);
		if (eventData["block"] == true) {
			return;
		}

		reinterpret_cast<void(__thiscall *)(MobileActor*, bool)>(TES3_MobileActor_stopCombat)(this, something);

		// Prepare our event data.
		eventData = state.create_table();
		eventData["actor"] = mwse::lua::makeLuaObject(this);

		// If our event data says to block, don't let the object activate.
		mwse::lua::event::trigger("combatStopped", eventData);
	}
}

#include "TES3LeveledList.h"

#include "LuaManager.h"

#define TES3_LeveledCreature_resolve 0x4CF870
#define TES3_LeveledItem_resolve 0x4D0BD0

namespace TES3 {
	Object * LeveledCreature::resolve() {
		// Call the original function.
		Object * result = reinterpret_cast<Object*(__thiscall *)(LeveledCreature*)>(TES3_LeveledCreature_resolve)(this);

		// Allow the event to override the pick.
		sol::table eventData = mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::LeveledCreaturePickedEvent(this, result));
		if (eventData.valid()) {
			if (eventData["block"] == true) {
				return nullptr;
			}

			result = eventData["pick"];
		}

		return result;
	}

	Object * LeveledItem::resolve() {
		// Call the original function.
		Object * result = reinterpret_cast<Object*(__thiscall *)(LeveledItem*)>(TES3_LeveledItem_resolve)(this);

		// Allow the event to override the pick.
		sol::table eventData = mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::LeveledItemPickedEvent(this, result));
		if (eventData.valid()) {
			if (eventData["block"] == true) {
				return nullptr;
			}
			
			result = eventData["pick"];
		}

		return result;
	}
}

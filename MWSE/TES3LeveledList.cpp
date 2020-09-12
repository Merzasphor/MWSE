#include "TES3LeveledList.h"

#include "LuaManager.h"

#include "LuaLeveledCreaturePickedEvent.h"
#include "LuaLeveledItemPickedEvent.h"

#define TES3_LeveledCreature_resolve 0x4CF870
#define TES3_LeveledItem_resolve 0x4D0BD0

namespace TES3 {
	Object * LeveledCreature::resolve() {
		// Call the original function.
		Object * result = reinterpret_cast<Object*(__thiscall *)(LeveledCreature*)>(TES3_LeveledCreature_resolve)(this);

		// Allow the event to override the pick.
		if (mwse::lua::event::LeveledCreaturePickedEvent::getEventEnabled()) {
			auto& luaManager = mwse::lua::LuaManager::getInstance();
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::object eventResult = stateHandle.triggerEvent(new mwse::lua::event::LeveledCreaturePickedEvent(this, result));
			if (eventResult.valid()) {
				sol::table eventData = eventResult;

				if (eventData.get_or("block", false)) {
					return nullptr;
				}

				result = eventData["pick"];
			}
		}

		return result;
	}

	const auto TES3_LeveledCreature_InsertEntry = reinterpret_cast<bool(__thiscall*)(LeveledCreature*, BaseObject*, short)>(0x4CFCC0);
	bool LeveledCreature::insert(BaseObject* entry, short level) {
		return TES3_LeveledCreature_InsertEntry(this, entry, level);
	}

	const auto TES3_LeveledCreature_RemoveEntry = reinterpret_cast<bool(__thiscall*)(LeveledCreature*, BaseObject*, short)>(0x4CFC40);
	bool LeveledCreature::remove(BaseObject* entry, short level) {
		return TES3_LeveledCreature_RemoveEntry(this, entry, level);
	}

	Object * LeveledItem::resolve() {
		// Call the original function.
		Object * result = reinterpret_cast<Object*(__thiscall *)(LeveledItem*)>(TES3_LeveledItem_resolve)(this);

		// Allow the event to override the pick.
		if (mwse::lua::event::LeveledItemPickedEvent::getEventEnabled()) {
			auto& luaManager = mwse::lua::LuaManager::getInstance();
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::object eventResult = stateHandle.triggerEvent(new mwse::lua::event::LeveledItemPickedEvent(this, result));
			if (eventResult.valid()) {
				sol::table eventData = eventResult;

				if (eventData.get_or("block", false)) {
					return nullptr;
				}

				result = eventData["pick"];
			}
		}

		return result;
	}

	const auto TES3_LeveledItem_InsertEntry = reinterpret_cast<bool(__thiscall*)(LeveledItem*, BaseObject*, short)>(0x4D0EE0);
	bool LeveledItem::insert(BaseObject* entry, short level) {
		return TES3_LeveledItem_InsertEntry(this, entry, level);
	}

	const auto TES3_LeveledItem_RemoveEntry = reinterpret_cast<bool(__thiscall*)(LeveledItem*, BaseObject*, short)>(0x4D0E60);
	bool LeveledItem::remove(BaseObject* entry, short level) {
		return TES3_LeveledItem_RemoveEntry(this, entry, level);
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::LeveledCreature)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::LeveledItem)

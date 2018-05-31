#include "TES3InventoryLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaUtil.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Inventory() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::LeveledListNode>("TES3LeveledListNode",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"object", sol::readonly_property([](TES3::LeveledListNode& self) { return makeLuaObject(self.object); }),
				"levelRequired", sol::readonly_property(&TES3::LeveledListNode::levelRequirement)

				);

			state.new_usertype<TES3::LeveledList>("TES3LeveledList",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::LeveledList::objectType,

				"id", sol::readonly_property(&TES3::LeveledList::getObjectID),

				"flags", &TES3::LeveledList::flags,

				"list", sol::readonly_property(&TES3::LeveledList::itemList),
				"count", sol::readonly_property(&TES3::LeveledList::itemList),
				"chanceForNothing", sol::readonly_property(&TES3::LeveledList::chanceForNothing),

				//
				// Functions.
				//

				"pickFrom", [](TES3::LeveledList& self) { return makeLuaObject(self.resolve()); }

				);
		}
	}
}

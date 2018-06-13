#include "TES3InventoryLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3LeveledList.h"

namespace mwse {
	namespace lua {
		void bindTES3LeveledList() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::LeveledListNode
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::LeveledListNode>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("levelRequired", sol::readonly_property(&TES3::LeveledListNode::levelRequirement));

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("object", sol::readonly_property([](TES3::LeveledListNode& self) { return makeLuaObject(self.object); }));

				// Finish up our usertype.
				state.set_usertype("tes3leveledListNode", usertypeDefinition);
			}

			// Binding for TES3::LeveledList
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::LeveledList>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());

				// Allow object to be converted to strings using their object ID.
				usertypeDefinition.set(sol::meta_function::to_string, &TES3::LeveledList::getObjectID);

				// Basic property binding.
				usertypeDefinition.set("chanceForNothing", sol::readonly_property(&TES3::LeveledList::chanceForNothing));
				usertypeDefinition.set("count", sol::readonly_property(&TES3::LeveledList::itemCount));
				usertypeDefinition.set("flags", sol::readonly_property(&TES3::LeveledList::flags));
				usertypeDefinition.set("list", sol::readonly_property(&TES3::LeveledList::itemList));

				// Basic function binding.
				usertypeDefinition.set("pickFrom", [](TES3::LeveledList& self) { return makeLuaObject(self.resolve()); });

				// Finish up our usertype.
				state.set_usertype("tes3leveledList", usertypeDefinition);
			}
		}
	}
}

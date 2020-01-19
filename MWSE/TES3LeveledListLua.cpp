#include "TES3InventoryLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3LeveledList.h"

namespace mwse {
	namespace lua {
		void bindTES3LeveledList() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::LeveledListNode
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::LeveledListNode>("tes3leveledListNode");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["levelRequired"] = &TES3::LeveledListNode::levelRequirement;

				// Access to other objects that need to be packaged.
				usertypeDefinition["object"] = sol::readonly_property([](TES3::LeveledListNode& self) { return makeLuaObject(self.object); });
			}

			// Binding for TES3::LeveledCreature
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::LeveledCreature>("tes3leveledCreature");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::PhysicalObject, TES3::Object, TES3::BaseObject>();
				setUserdataForPhysicalObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["chanceForNothing"] = sol::readonly_property(&TES3::LeveledCreature::chanceForNothing);
				usertypeDefinition["count"] = sol::readonly_property(&TES3::LeveledCreature::itemCount);
				usertypeDefinition["flags"] = sol::readonly_property(&TES3::LeveledCreature::flags);
				usertypeDefinition["list"] = sol::readonly_property(&TES3::LeveledCreature::itemList);

				// Basic function binding.
				usertypeDefinition["pickFrom"] = [](TES3::LeveledCreature& self) { return makeLuaObject(self.resolve()); };
			}

			// Binding for TES3::LeveledItem
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::LeveledItem>("tes3leveledItem");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::PhysicalObject, TES3::Object, TES3::BaseObject>();
				setUserdataForPhysicalObject(usertypeDefinition);

				// Allow object to be converted to strings using their object ID.
				usertypeDefinition[sol::meta_function::to_string] = &TES3::LeveledItem::getObjectID;

				// Basic property binding.
				usertypeDefinition["chanceForNothing"] = sol::readonly_property(&TES3::LeveledItem::chanceForNothing);
				usertypeDefinition["count"] = sol::readonly_property(&TES3::LeveledItem::itemCount);
				usertypeDefinition["flags"] = sol::readonly_property(&TES3::LeveledItem::flags);
				usertypeDefinition["list"] = sol::readonly_property(&TES3::LeveledItem::itemList);

				// Basic function binding.
				usertypeDefinition["pickFrom"] = [](TES3::LeveledItem& self) { return makeLuaObject(self.resolve()); };
			}
		}
	}
}

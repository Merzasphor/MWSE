#include "TES3MobileNPCLua.h"

#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3MobileNPC() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::MobileNPC>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::MobileActor, TES3::MobileObject>());

			// All binding is in the NPC function, so that mobile player doesn't have extra lookup times.
			setUserdataForMobileNPC(usertypeDefinition);

			// Basic function binding.
			usertypeDefinition.set("equip", &TES3::MobileActor::equipItem);
			usertypeDefinition.set("unequipArmor", &TES3::MobileActor::unequipArmor);
			usertypeDefinition.set("unequipClothing", &TES3::MobileActor::unequipClothing);

			// Finish up our usertype.
			state.set_usertype("tes3mobileNPC", usertypeDefinition);
		}
	}
}

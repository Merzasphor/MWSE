#include "TES3ActorLua.h"

#include "sol.hpp"

#include "LuaManager.h"

#include "TES3Actor.h"

namespace mwse {
	namespace lua {
		void bindTES3Actor() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Actor>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());

			// Basic property binding.
			usertypeDefinition.set("actorFlags", sol::readonly_property(&TES3::Actor::actorFlags));
			usertypeDefinition.set("cloneCount", sol::readonly_property(&TES3::Actor::cloneCount));
			usertypeDefinition.set("equipment", sol::readonly_property(&TES3::Actor::equipment));
			usertypeDefinition.set("inventory", sol::readonly_property(&TES3::Actor::inventory));

			// Functions exposed as properties.
			usertypeDefinition.set("barterGold", sol::property(&TES3::Actor::getBaseBarterGold, &TES3::Actor::setBaseBarterGold));

			// Finish up our usertype.
			state.set_usertype("tes3actor", usertypeDefinition);
		}
	}
}

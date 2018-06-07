#include "TES3FactionLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Faction.h"

namespace mwse {
	namespace lua {
		void bindTES3Faction() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::Faction::Rank
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Faction::Rank>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("reputation", &TES3::Faction::Rank::reputation);

				// Indirect bindings to unions and arrays.
				usertypeDefinition.set("attributes", sol::readonly_property([](TES3::Faction::Rank& self) { return std::ref(self.reqAttributes); }));
				usertypeDefinition.set("skills", sol::readonly_property([](TES3::Faction::Rank& self) { return std::ref(self.reqSkills); }));

				// Finish up our usertype.
				state.set_usertype("tes3factionRank", usertypeDefinition);
			}

			// Binding for TES3::Faction::ReactionNode
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Faction::ReactionNode>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("reputation", &TES3::Faction::ReactionNode::reaction);
				usertypeDefinition.set("faction", sol::readonly_property([](TES3::Faction::ReactionNode& self) { return makeLuaObject(self.faction); }));

				// Finish up our usertype.
				state.set_usertype("tes3factionReaction", usertypeDefinition);
			}

			// Binding for TES3::Faction
			//! TODO: Provide a more friendly way to access rank names. Probably needs to be hidden behind its own struct.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Faction>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());

				// Basic property binding.
				usertypeDefinition.set("reactions", sol::readonly_property(&TES3::Faction::reactions));

				// Indirect bindings to unions and arrays.
				usertypeDefinition.set("attributes", sol::property([](TES3::Faction& self) { return std::ref(self.attributes); }));
				usertypeDefinition.set("ranks", sol::readonly_property([](TES3::Faction& self) { return std::ref(self.ranks); }));
				usertypeDefinition.set("skills", sol::property([](TES3::Faction& self) { return std::ref(self.skills); }));

				// Functions exposed as properties.
				usertypeDefinition.set("name", sol::property(&TES3::Faction::getName, &TES3::Faction::setName));

				// Finish up our usertype.
				state.set_usertype("tes3faction", usertypeDefinition);
			}
		}
	}
}

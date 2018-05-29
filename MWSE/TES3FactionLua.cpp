#include "TES3FactionLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace TES3 {
	sol::object Faction::getReactions() {
		sol::state& state = mwse::lua::LuaManager::getInstance().getState();

		sol::table result = state.create_table();
		auto * node = reactions.head;
		while (node) {
			result.add(node->data);
			node = node->next;
		}
		return result;
	}
}

namespace mwse {
	namespace lua {
		void bindTES3Faction() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::Faction::Rank>("TES3FactionRank",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"attributes", sol::property([](TES3::Faction::Rank& self) { return std::ref(self.reqAttributes); }),
				"skills", sol::property([](TES3::Faction::Rank& self) { return std::ref(self.reqSkills); }),
				"reputation", &TES3::Faction::Rank::reputation

				);

			state.new_usertype<TES3::Faction::ReactionNode>("TES3FactionReaction",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"faction", sol::readonly_property(&TES3::Faction::ReactionNode::faction),
				"reaction", &TES3::Faction::ReactionNode::reaction

				);

			state.new_usertype<TES3::Faction>("TES3Faction",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::meta_function::to_string, &TES3::Faction::getObjectID,

				//
				// Properties.
				//

				"objectType", &TES3::Faction::objectType,

				"id", sol::readonly_property(&TES3::Faction::getObjectID),
				"name", sol::property([](TES3::Faction& self) { return self.name; }),

				"skills", sol::property([](TES3::Faction& self) { return std::ref(self.skills); }),

				"ranks", sol::readonly_property([](TES3::Faction& self) { return std::ref(self.ranks); }),

				"reactions", sol::readonly_property(&TES3::Faction::getReactions),

				//
				// Functions.
				//

				"getRankName", [](TES3::Faction& self, int index) { return self.rankNames[index-1]; }

				);
		}
	}
}

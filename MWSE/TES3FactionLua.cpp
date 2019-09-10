#include "TES3FactionLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"
#include "TES3CollectionsLua.h"

#include "TES3Faction.h"

namespace mwse {
	namespace lua {
		void bindTES3Faction() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::Faction::Rank
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Faction::Rank>("tes3factionRank");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["reputation"] = &TES3::Faction::Rank::reputation;

				// Indirect bindings to unions and arrays.
				usertypeDefinition["attributes"] = sol::readonly_property([](TES3::Faction::Rank& self) { return std::ref(self.reqAttributes); });
				usertypeDefinition["skills"] = sol::readonly_property([](TES3::Faction::Rank& self) { return std::ref(self.reqSkills); });
			}

			// Binding for TES3::Faction::ReactionNode
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Faction::ReactionNode>("tes3factionReaction");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["reputation"] = &TES3::Faction::ReactionNode::reaction;
				usertypeDefinition["faction"] = sol::readonly_property([](TES3::Faction::ReactionNode& self) { return makeLuaObject(self.faction); });
			}

			// Binding for TES3::Faction
			//! TODO: Provide a more friendly way to access rank names. Probably needs to be hidden behind its own struct.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Faction>("tes3faction");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::BaseObject>();
				setUserdataForBaseObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["reactions"] = sol::readonly_property(&TES3::Faction::reactions);
				usertypeDefinition["playerReputation"] = &TES3::Faction::playerReputation;
				usertypeDefinition["playerJoined"] = sol::property(
					[](TES3::Faction& self) { return self.getMembershipFlag(TES3::FactionMembershipFlag::PlayerJoined); },
					[](TES3::Faction& self, bool set) { self.setMembershipFlag(TES3::FactionMembershipFlag::PlayerJoined, set); }
				);
				usertypeDefinition["playerExpelled"] = sol::property(
					[](TES3::Faction& self) { return self.getMembershipFlag(TES3::FactionMembershipFlag::PlayerExpelled); },
					[](TES3::Faction& self, bool set) { self.setMembershipFlag(TES3::FactionMembershipFlag::PlayerExpelled, set); }
				);

				// Indirect bindings to unions and arrays.
				usertypeDefinition["attributes"] = sol::property([](TES3::Faction& self) { return std::ref(self.attributes); });
				usertypeDefinition["ranks"] = sol::readonly_property([](TES3::Faction& self) { return std::ref(self.ranks); });
				usertypeDefinition["skills"] = sol::property([](TES3::Faction& self) { return std::ref(self.skills); });

				// Functions exposed as properties.
				usertypeDefinition["name"] = sol::property(&TES3::Faction::getName, &TES3::Faction::setName);
				usertypeDefinition["playerRank"] = sol::property(&TES3::Faction::getEffectivePlayerRank, &TES3::Faction::setEffectivePlayerRank);
			}

			// Bind iterator access.
			bindGenericObjectIterator<TES3::Faction>("tes3factionIterator", "tes3factionIteratorNode");
		}
	}
}

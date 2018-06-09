#include "TES3RaceLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Race.h"

namespace mwse {
	namespace lua {
		void bindTES3Race() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::Race::SkillBonus.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Race::SkillBonus>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("skill", &TES3::Race::SkillBonus::skill);
				usertypeDefinition.set("bonus", &TES3::Race::SkillBonus::bonus);

				// Finish up our usertype.
				state.set_usertype("tes3raceSkillBonus", usertypeDefinition);
			}

			// Binding for TES3::Race::BaseAttribute.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Race::BaseAttribute>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("male", &TES3::Race::BaseAttribute::male);
				usertypeDefinition.set("female", &TES3::Race::BaseAttribute::female);

				// Finish up our usertype.
				state.set_usertype("tes3raceBaseAttribute", usertypeDefinition);
			}

			// Binding for TES3::Race::HeightWeight.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Race::HeightWeight>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("male", &TES3::Race::HeightWeight::male);
				usertypeDefinition.set("female", &TES3::Race::HeightWeight::female);

				// Finish up our usertype.
				state.set_usertype("tes3raceHeightWeight", usertypeDefinition);
			}

			// Binding for TES3::Race.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Race>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());

				// Basic property binding.
				usertypeDefinition.set("flags", &TES3::Race::flags);
				usertypeDefinition.set("height", &TES3::Race::height);
				usertypeDefinition.set("weight", &TES3::Race::weight);

				// Indirect bindings to unions and arrays.
				usertypeDefinition.set("baseAttributes", sol::readonly_property([](TES3::Race& self) { return std::ref(self.baseAttributes); }));
				usertypeDefinition.set("skillBonuses", sol::readonly_property([](TES3::Race& self) { return std::ref(self.skillBonuses); }));

				// Functions exposed as properties.
				usertypeDefinition.set("name", sol::readonly_property([](TES3::Race& self) { return self.name; }));

				// Finish up our usertype.
				state.set_usertype("tes3race", usertypeDefinition);
			}
		}
	}
}

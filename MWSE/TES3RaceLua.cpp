#include "TES3RaceLua.h"

#include "LuaManager.h"

#include "TES3Race.h"

namespace mwse {
	namespace lua {
		void bindTES3Race() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::Race::SkillBonus>("TES3RaceSkillBonus",
				"new", sol::no_constructor,

				"skill", &TES3::Race::SkillBonus::skill,
				"bonus", &TES3::Race::SkillBonus::bonus
				);

			state.new_usertype<TES3::Race::BaseAttribute>("TES3RaceBaseAttribute",
				"new", sol::no_constructor,

				"male", &TES3::Race::BaseAttribute::male,
				"female", &TES3::Race::BaseAttribute::female
				);

			state.new_usertype<TES3::Race::HeightWeight>("TES3RaceHeightWeight",
				"new", sol::no_constructor,

				"male", &TES3::Race::HeightWeight::male,
				"female", &TES3::Race::HeightWeight::female
				);

			state.new_usertype<TES3::Race>("TES3Race",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Race::objectType,

				"id", sol::readonly_property(&TES3::Race::getObjectID),
				"name", sol::readonly_property([](TES3::Race& self) { return self.name; }),

				"flags", &TES3::Race::flags,

				"skillBonuses", sol::readonly_property([](TES3::Race& self) { return std::ref(self.skillBonuses); }),
				"baseAttributes", sol::readonly_property([](TES3::Race& self) { return std::ref(self.baseAttributes); }),
				"height", &TES3::Race::height,
				"weight", &TES3::Race::weight

				);
		}
	}
}

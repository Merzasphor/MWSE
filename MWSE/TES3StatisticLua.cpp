#include "TES3StatisticLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Statistic.h"


namespace mwse {
	namespace lua {
		void bindTES3Statistic() {
			sol::state& state = LuaManager::getInstance().getState();

			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Statistic>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("base", sol::property(&TES3::Statistic::getBase, &TES3::Statistic::setBase));
				usertypeDefinition.set("current", sol::property(&TES3::Statistic::getCurrent, [](TES3::Statistic& self, float value) { self.setCurrentCapped(value, false); }));
				usertypeDefinition.set("normalized", sol::property(&TES3::Statistic::getNormalized));

				// Finish up our usertype.
				state.set_usertype("tes3statistic", usertypeDefinition);
			}

			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::SkillStatistic>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("base", sol::property(&TES3::SkillStatistic::getBase, &TES3::SkillStatistic::setBase));
				usertypeDefinition.set("current", sol::property(&TES3::SkillStatistic::getCurrent, [](TES3::SkillStatistic& self, float value) { self.setCurrentCapped(value, false); }));
				usertypeDefinition.set("normalized", sol::property(&TES3::SkillStatistic::getNormalized));
				usertypeDefinition.set("type", &TES3::SkillStatistic::type);

				// Finish up our usertype.
				state.set_usertype("tes3statisticSkill", usertypeDefinition);
			}
		}
	}
}



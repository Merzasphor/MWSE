#include "TES3StatisticLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Statistic.h"


namespace mwse {
	namespace lua {
		void bindTES3Statistic() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::Statistic>("TES3Statistic",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"base", sol::property(&TES3::Statistic::getBase, [](TES3::Statistic& self, float value) { self.setBase(value); }),
				"current", sol::property(&TES3::Statistic::getCurrent, [](TES3::Statistic& self, float value) { self.setCurrentCapped(value, false); })

				);

			state.new_usertype<TES3::SkillStatistic>("TES3SkillStatistic",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"base", sol::property(&TES3::SkillStatistic::getBase, [](TES3::SkillStatistic& self, float value) { self.setBase(value); }),
				"current", sol::property(&TES3::SkillStatistic::getCurrent, [](TES3::SkillStatistic& self, float value) { self.setCurrentCapped(value, false); }),
				"type", &TES3::SkillStatistic::type

				);
		}
	}
}



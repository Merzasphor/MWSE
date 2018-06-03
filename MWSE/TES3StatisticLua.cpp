#include "TES3StatisticLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3Statistic.h"

namespace TES3 {
	void Statistic::luaModBase(float value) {
		modBaseCapped(value, false, false);
	}

	void Statistic::luaSetBase(float value) {
		setBase(value);
	}

	void Statistic::luaModCurrent(float value) {
		modCurrentCapped(value, false, false, false);
	}

	void Statistic::luaSetCurrent(float value) {
		setCurrentCapped(value, false);
	}
}

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

				"base", sol::property(&TES3::Statistic::getBase, &TES3::Statistic::luaSetBase),
				"current", sol::property(&TES3::Statistic::getCurrent, &TES3::Statistic::luaSetCurrent)

				);

			state.new_usertype<TES3::SkillStatistic>("TES3SkillStatistic",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"base", sol::property(&TES3::SkillStatistic::getBase, &TES3::SkillStatistic::luaSetBase),
				"current", sol::property(&TES3::SkillStatistic::getCurrent, &TES3::SkillStatistic::luaSetCurrent),
				"type", &TES3::SkillStatistic::type

				);
		}
	}
}



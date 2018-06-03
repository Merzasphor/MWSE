#include "TES3ActionDataLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"

namespace TES3 {
	sol::object ActionData::getTarget() {
		return mwse::lua::makeLuaObject(target);
	}

	sol::object ActionData::getHitTarget() {
		return mwse::lua::makeLuaObject(hitTarget);
	}

	sol::object ActionData::getNockedProjectile() {
		return mwse::lua::makeLuaObject(nockedProjectile);
	}

	sol::object ActionData::getStolenFrom() {
		return mwse::lua::makeLuaObject(stolenFromFactionOrNPC);
	}
}

namespace mwse {
	namespace lua {
		void bindTES3ActionData() {
			LuaManager::getInstance().getState().new_usertype<TES3::ActionData>("TES3ActionData",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"attackSwing", &TES3::ActionData::attackSwing,
				"physicalDamage", &TES3::ActionData::physicalDamage,

				"aiBehaviourState", &TES3::ActionData::aiBehaviourState,
				"attackDirection", &TES3::ActionData::attackDirection,
				"animationAttackState", &TES3::ActionData::animStateAttack,
				"currentAnimationGroup", &TES3::ActionData::currentAnimGroup,

				"lastBarterHoursPassed", &TES3::ActionData::lastBarterHoursPassed,

				"walkDestination", &TES3::ActionData::walkDestination,

				"target", sol::readonly_property(&TES3::ActionData::getTarget),
				"hitTarget", sol::readonly_property(&TES3::ActionData::getHitTarget),

				"nockedProjectile", sol::readonly_property(&TES3::ActionData::getNockedProjectile),

				"stolenFrom", sol::readonly_property(&TES3::ActionData::getStolenFrom)

				);
		}
	}
}

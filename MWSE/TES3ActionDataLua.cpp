#include "TES3ActionDataLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3ActionData.h"
#include "TES3MobileActor.h"
#include "TES3Item.h"

namespace mwse {
	namespace lua {
		void bindTES3ActionData() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::ActionData>("tes3actionData");
			usertypeDefinition["new"] = sol::no_constructor;

			// Basic property binding.
			usertypeDefinition["aiBehaviorState"] = &TES3::ActionData::aiBehaviourState;
			usertypeDefinition["animationAttackState"] = &TES3::ActionData::animStateAttack;
			usertypeDefinition["attackDirection"] = &TES3::ActionData::attackDirection;
			usertypeDefinition["attackSwing"] = &TES3::ActionData::attackSwing;
			usertypeDefinition["currentAnimationGroup"] = &TES3::ActionData::currentAnimGroup;
			usertypeDefinition["lastBarterHoursPassed"] = &TES3::ActionData::lastBarterHoursPassed;
			usertypeDefinition["physicalDamage"] = &TES3::ActionData::physicalDamage;
			usertypeDefinition["walkDestination"] = &TES3::ActionData::walkDestination;

			// Access to other objects that need to be packaged.
			usertypeDefinition["hitTarget"] = sol::readonly_property([](TES3::ActionData& self) { return self.hitTarget; });
			usertypeDefinition["nockedProjectile"] = sol::readonly_property([](TES3::ActionData& self) { return self.nockedProjectile; });
			usertypeDefinition["stolenFrom"] = sol::readonly_property([](TES3::ActionData& self) { return self.stolenFromFactionOrNPC; });
			usertypeDefinition["target"] = sol::readonly_property([](TES3::ActionData& self) { return self.target; });
		}
	}
}

#include "TES3ActionDataLua.h"

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
			auto usertypeDefinition = state.create_simple_usertype<TES3::ActionData>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Basic property binding.
			usertypeDefinition.set("aiBehaviorState", &TES3::ActionData::aiBehaviourState);
			usertypeDefinition.set("animationAttackState", &TES3::ActionData::animStateAttack);
			usertypeDefinition.set("attackDirection", &TES3::ActionData::attackDirection);
			usertypeDefinition.set("attackSwing", &TES3::ActionData::attackSwing);
			usertypeDefinition.set("currentAnimationGroup", &TES3::ActionData::currentAnimGroup);
			usertypeDefinition.set("lastBarterHoursPassed", &TES3::ActionData::lastBarterHoursPassed);
			usertypeDefinition.set("physicalDamage", &TES3::ActionData::physicalDamage);
			usertypeDefinition.set("walkDestination", &TES3::ActionData::walkDestination);

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("hitTarget", sol::readonly_property([](TES3::ActionData& self) { return makeLuaObject(self.hitTarget); }));
			usertypeDefinition.set("nockedProjectile", sol::readonly_property([](TES3::ActionData& self) { return makeLuaObject(self.nockedProjectile); }));
			usertypeDefinition.set("stolenFrom", sol::readonly_property([](TES3::ActionData& self) { return makeLuaObject(self.stolenFromFactionOrNPC); }));
			usertypeDefinition.set("target", sol::readonly_property([](TES3::ActionData& self) { return makeLuaObject(self.target); }));

			// Finish up our usertype.
			state.set_usertype("tes3actionData", usertypeDefinition);
		}
	}
}

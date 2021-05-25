#include "TES3ActorAnimationControllerLua.h"

#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3ActorAnimationController.h"
#include "TES3MobileActor.h"

namespace mwse {
	namespace lua {
		void bindTES3ActorAnimationController() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::ActorAnimationController>("tes3actorAnimationController");
			usertypeDefinition["new"] = sol::no_constructor;

			// Basic property binding.
			usertypeDefinition["mobile"] = sol::readonly_property(&TES3::ActorAnimationController::mobileActor);

			// Custom properties.
			usertypeDefinition["weaponSpeed"] = sol::property(&TES3::ActorAnimationController::getWeaponAnimSpeed, &TES3::ActorAnimationController::setWeaponAnimSpeed);
		}
	}
}

#include "TES3MobControllerLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3MobController.h"

namespace mwse {
	namespace lua {
		void bindTES3MobController() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::MobPlayerController.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::MobPlayerController>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic function binding.
				usertypeDefinition.set("detectPresence", &TES3::MobPlayerController::detectPresence);
				usertypeDefinition.set("detectSneak", &TES3::MobPlayerController::detectSneak);
				usertypeDefinition.set("checkRadius", &TES3::MobPlayerController::checkRadius);
				usertypeDefinition.set("checkPlayerDistance", &TES3::MobPlayerController::checkPlayerDistance);

				// Finish up our usertype.
				state.set_usertype("tes3mobPlayerController", usertypeDefinition);
			}

			// Binding for TES3::ProjectileController.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::ProjectileController>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic function binding.
	
				// Finish up our usertype.
				state.set_usertype("tes3projtectileController", usertypeDefinition);
			}
		

			// Binding for TES3::MobController.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::MobController>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("mobPlayerController", sol::readonly_property(&TES3::MobController::mobPlayerController));
				usertypeDefinition.set("projectileController", sol::readonly_property(&TES3::MobController::projectileController));
		
				// Finish up our usertype.
				state.set_usertype("tes3mobController", usertypeDefinition);
			}
		}
	}
}

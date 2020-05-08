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

			// Binding for TES3::MobController_0x24.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::MobController_0x24>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic function binding.
				usertypeDefinition.set("detectPresence", &TES3::MobController_0x24::detectPresence);
				usertypeDefinition.set("detectSneak", &TES3::MobController_0x24::detectSneak);
				usertypeDefinition.set("checkRadius", &TES3::MobController_0x24::checkRadius);
				usertypeDefinition.set("checkPlayerDistance", &TES3::MobController_0x24::checkPlayerDistance);

				// Finish up our usertype.
				state.set_usertype("tes3mobController_0x24", usertypeDefinition);
			}

			// Binding for TES3::ProjectileController.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::ProjectileController>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic function binding.
	
				// Finish up our usertype.
				state.set_usertype("tes3projectileController", usertypeDefinition);
			}
		

			// Binding for TES3::MobController.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::MobController>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("mobController_0x24", sol::readonly_property(&TES3::MobController::MobController_0x24));
				usertypeDefinition.set("projectileController", sol::readonly_property(&TES3::MobController::projectileController));
		
				// Finish up our usertype.
				state.set_usertype("tes3mobController", usertypeDefinition);
			}
		}
	}
}

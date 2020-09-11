#include "TES3MobControllerLua.h"

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
				auto usertypeDefinition = state.new_usertype<TES3::MobController_0x24>("tes3mobController_0x24");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic function binding.
				usertypeDefinition["aiDistaNCE"] = &TES3::MobController_0x24::aiDistance;
				usertypeDefinition["detectPresence"] = &TES3::MobController_0x24::detectPresence;
				usertypeDefinition["detectSneak"] = &TES3::MobController_0x24::detectSneak;
				usertypeDefinition["checkRadius"] = &TES3::MobController_0x24::checkRadius;
				usertypeDefinition["checkPlayerDistance"] = &TES3::MobController_0x24::checkPlayerDistance;

				// Functions exposed as properties.
				usertypeDefinition["aiDistanceScale"] = sol::property(&TES3::MobController_0x24::getAIDistanceScale, &TES3::MobController_0x24::setAIDistanceScale);
			}

			// Binding for TES3::ProjectileController.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::ProjectileController>("tes3projectileController");
				usertypeDefinition["new"] = sol::no_constructor;
			}
		

			// Binding for TES3::MobController.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::MobController>("tes3mobController");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["mobController_0x24"] = sol::readonly_property(&TES3::MobController::mobController_0x24);
				usertypeDefinition["projectileController"] = sol::readonly_property(&TES3::MobController::projectileController);
			}
		}
	}
}

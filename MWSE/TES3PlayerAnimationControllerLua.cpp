#include "TES3PlayerAnimationControllerLua.h"

#include "LuaUtil.h"
#include "LuaManager.h"

#include "NICamera.h"

#include "TES3PlayerAnimationController.h"

namespace mwse::lua {
	void bindTES3PlayerAnimationController() {
		// Get our lua state.
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;

		// Start our usertype.
		auto usertypeDefinition = state.new_usertype<TES3::PlayerAnimationController>("tes3playerAnimationController");
		usertypeDefinition["new"] = sol::no_constructor;

		// Basic property binding.
		usertypeDefinition["firstPersonHeadCameraNode"] = sol::readonly_property(&TES3::PlayerAnimationController::firstPersonHeadCameraNode);
		usertypeDefinition["cameraOffset"] = sol::readonly_property(&TES3::PlayerAnimationController::cameraOffset);
		usertypeDefinition["pickData"] = sol::readonly_property(&TES3::PlayerAnimationController::pickData);
		usertypeDefinition["is3rdPerson"] = sol::readonly_property(&TES3::PlayerAnimationController::is3rdPerson);
		usertypeDefinition["togglePOV"] = sol::readonly_property(&TES3::PlayerAnimationController::togglePOV);
		usertypeDefinition["allowVerticalAirControl"] = sol::readonly_property(&TES3::PlayerAnimationController::allowVerticalAirControl);
		usertypeDefinition["vanityCameraEnabled"] = sol::readonly_property(&TES3::PlayerAnimationController::vanityCameraEnabled);
		usertypeDefinition["useThirdPersonAfterVanityCameraDone"] = sol::readonly_property(&TES3::PlayerAnimationController::useThirdPersonAfterVanityCameraDone);
		usertypeDefinition["vanityCameraZ"] = sol::readonly_property(&TES3::PlayerAnimationController::vanityCameraZ);
		usertypeDefinition["vanityCameraDistance"] = sol::readonly_property(&TES3::PlayerAnimationController::vanityCameraDistance);
		usertypeDefinition["vanityCamera"] = sol::readonly_property(&TES3::PlayerAnimationController::vanityCamera);
		usertypeDefinition["shadowCameraMatrix"] = sol::readonly_property(&TES3::PlayerAnimationController::shadowCameraMatrix);

		// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
		usertypeDefinition[sol::base_classes] = sol::bases<TES3::ActorAnimationController>();
	}
}

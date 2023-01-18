#include "TES3PlayerAnimationController.h"

#include "LuaManager.h"
#include "LuaUtil.h"
#include "NINode.h"
#include "TES3MobilePlayer.h"
#include "TES3Reference.h"
#include "TES3WorldController.h"

#include "LuaCameraControlEvent.h"

namespace TES3 {
	TES3::Transform PlayerAnimationController::previousCameraTransform;
	TES3::Transform PlayerAnimationController::previousArmCameraTransform;

	bool PlayerAnimationController::force1stPerson() {
		if (is3rdPerson) {
			togglePOV = true;
		}
		return togglePOV;
	}

	bool PlayerAnimationController::force3rdPerson() {
		if (!is3rdPerson) {
			togglePOV = true;
		}
		return togglePOV;
	}

	const auto TES3_PlayerAnimationController_syncRotation = reinterpret_cast<void(__thiscall*)(PlayerAnimationController*)>(0x5438F0);
	void PlayerAnimationController::syncRotation() {
		const auto worldController = WorldController::get();

		// Save camera transforms for the cameraControl event.
		previousCameraTransform = worldController->worldCamera.cameraRoot->getTransforms();
		previousArmCameraTransform = worldController->armCamera.cameraRoot->getTransforms();

		// Call the original function.
		TES3_PlayerAnimationController_syncRotation(this);
	}
}

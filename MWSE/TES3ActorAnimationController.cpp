#include "TES3ActorAnimationController.h"

#include "LuaManager.h"

#include "LuaCalcMovementSpeedEvent.h"

#include "TES3MobilePlayer.h"
#include "TES3WorldController.h"

namespace TES3 {
	const auto TES3_ActorAnimationController_calculateMovementSpeed = reinterpret_cast<float(__thiscall*)(ActorAnimationController*)>(0x53E1A0);
	float ActorAnimationController::calculateMovementSpeed() {
		// Call the original function to get the default movement speed value.
		float speed = TES3_ActorAnimationController_calculateMovementSpeed(this);

		// Launch our event, and overwrite the speed with what was given back to us.
		if (mwse::lua::event::CalculateMovementSpeed::getEventEnabled()) {
			auto stateHandle = mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::CalculateMovementSpeed(mwse::lua::event::CalculateMovementSpeed::Move, this->mobileActor, speed));
			if (eventData.valid()) {
				speed = eventData["speed"];
			}
		}

		return speed;
	}

	const auto TES3_ActorAnimationController_getOpacity = reinterpret_cast<float(__thiscall*)(ActorAnimationController*)>(0x542130);
	float ActorAnimationController::getOpacity() {
		return TES3_ActorAnimationController_getOpacity(this);
	}

	const auto TES3_ActorAnimationController_setOpacity = reinterpret_cast<void(__thiscall*)(ActorAnimationController*, float)>(0x542030);
	void ActorAnimationController::setOpacity(float value) {
		TES3_ActorAnimationController_setOpacity(this, value);
	}

	void ActorAnimationController::updateOpacity() {
		const auto invisibility = mobileActor->effectAttributes[TES3::EffectAttribute::Invisibility];
		const auto chameleon = mobileActor->effectAttributes[TES3::EffectAttribute::Chameleon];

		// We care about invisibility first.
		if (invisibility > 0) {
			if (mobileActor == TES3::WorldController::get()->getMobilePlayer()) {
				setOpacity(0.25f);
			}
			else {
				setOpacity(0.05f);
			}
		}
		// Fall back to chameleon, based on magnitude.
		else if (chameleon > 0) {
			setOpacity(std::clamp(1.0f - (float(chameleon) / 100.0f), 0.25f, 75.0f));
		}
		// If all else fails we go for no Opacity.
		else {
			setOpacity(1.0f);
		}
	}
}

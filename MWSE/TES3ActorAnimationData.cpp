#include "TES3ActorAnimationData.h"

#include "LuaManager.h"

#include "LuaCalcMovementSpeedEvent.h"

#define TES3_ActorAnimationData_calculateMovementSpeed 0x53E1A0

namespace TES3 {
	float ActorAnimationData::calculateMovementSpeed() {
		// Call the original function to get the default movement speed value.
		float speed = reinterpret_cast<float(__thiscall *)(ActorAnimationData*)>(TES3_ActorAnimationData_calculateMovementSpeed)(this);

		// Launch our event, and overwrite the speed with what was given back to us.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::CalculateMovementSpeed(mwse::lua::event::CalculateMovementSpeed::Move, this->mobileActor, speed));
		if (eventData.valid()) {
			speed = eventData["speed"];
		}

		return speed;
	}
}

#include "TES3MobileCreature.h"

#include "LuaManager.h"

#include "LuaCalcMovementSpeedEvent.h"

#define TES3_MobileCreature_calcWalkSpeed 0x55AAF0

namespace TES3 {
	float MobileCreature::calculateWalkSpeed() {
		// Call the original function to get the default walk value.
		float speed = reinterpret_cast<float(__thiscall *)(MobileCreature*)>(TES3_MobileCreature_calcWalkSpeed)(this);

		// Launch our event, and overwrite the speed with what was given back to us.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::CalculateMovementSpeed(mwse::lua::event::CalculateMovementSpeed::Walk, this, speed));
		if (eventData.valid()) {
			speed = eventData["speed"];
		}

		return speed;
	}
}

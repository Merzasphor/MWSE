#include "TES3MobileNPC.h"

#include "LuaManager.h"

#define TES3_MobileNPC_calcWalkSpeed 0x526F70

namespace TES3 {
	float MobileNPC::calculateWalkSpeed() {
		// Call the original function to get the default walk value.
		float speed = reinterpret_cast<float(__thiscall *)(MobileNPC*)>(TES3_MobileNPC_calcWalkSpeed)(this);

		// Launch our event, and overwrite the speed with what was given back to us.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::CalculateMovementSpeed(mwse::lua::event::CalculateMovementSpeed::Walk, this, speed));
		if (eventData.valid()) {
			speed = eventData["speed"];
		}

		return speed;
	}
}

#include "TES3MobileObject.h"

#include "LuaManager.h"

#define TES3_MobileObject_onActorCollision 0x573860
#define TES3_MobileObject_onWaterImpact 0x5620D0

namespace TES3 {
	char MobileObject::onActorCollision(int referenceIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->hitReferences->hit[referenceIndex].reference;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		char result = reinterpret_cast<char(__thiscall *)(MobileObject*, int)>(TES3_MobileObject_onActorCollision)(this, referenceIndex);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::MobileObjectActorCollisionEvent(this, hitReference));

		return result;
	}

	char MobileObject::onWaterImpact(signed char inWater) {
		// Call the original function. We can't invoke the vtable here because we overwrite it.
		char result = reinterpret_cast<char(__thiscall *)(MobileObject*, signed char)>(TES3_MobileObject_onWaterImpact)(this, inWater);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::MobileObjectWaterImpactEvent(this, inWater));

		return result;
	}
}

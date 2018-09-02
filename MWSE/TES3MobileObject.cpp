#include "TES3MobileObject.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "LuaMobileObjectCollisionEvent.h"

#include "TES3Reference.h"

#define TES3_MobileObject_onActorCollision 0x5615A0
#define TES3_MobileObject_onObjectCollision 0x5615C0
#define TES3_MobileObject_onTerrainCollision 0x5615E0
#define TES3_MobileObject_onWaterCollision TES3_MobileObject_onTerrainCollision

namespace TES3 {
	signed char MobileObject::onActorCollision(int hitReferenceIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->hitReferences->hit[hitReferenceIndex].reference;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		signed char result = reinterpret_cast<char(__thiscall *)(MobileObject*, int)>(TES3_MobileObject_onActorCollision)(this, hitReferenceIndex);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));

		return result;
	}

	signed char MobileObject::onObjectCollision(int hitReferenceIndex, signed char flag) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->hitReferences->hit[hitReferenceIndex].reference;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		signed char result = reinterpret_cast<char(__thiscall *)(MobileObject*, int, signed char)>(TES3_MobileObject_onObjectCollision)(this, hitReferenceIndex, flag);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));

		return result;
	}

	signed char MobileObject::onTerrainCollision(int hitReferenceIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->hitReferences->hit[hitReferenceIndex].reference;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		signed char result = reinterpret_cast<char(__thiscall *)(MobileObject*, int)>(TES3_MobileObject_onTerrainCollision)(this, hitReferenceIndex);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));

		return result;
	}

	signed char MobileObject::onWaterCollision(int hitReferenceIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->hitReferences->hit[hitReferenceIndex].reference;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		signed char result = reinterpret_cast<char(__thiscall *)(MobileObject*, int)>(TES3_MobileObject_onWaterCollision)(this, hitReferenceIndex);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));

		return result;
	}

	void MobileObject::setImpulseVelocityFromLua(sol::stack_object value) {
		// Use our util class to support vectors or a table.
		mwse::lua::setVectorFromLua(&impulseVelocity, value);
	}

	void MobileObject::setPositionFromLua(sol::stack_object value) {
		// Use our util class to support vectors or a table.
		mwse::lua::setVectorFromLua(&position, value);

		// Update the reference if possible.
		if (reference) {
			reference->setPositionFromLua(value);
		}
	}

	void MobileObject::setVelocityFromLua(sol::stack_object value) {
		// Use our util class to support vectors or a table.
		mwse::lua::setVectorFromLua(&velocity, value);
	}
}

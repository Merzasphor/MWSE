#include "TES3MobileObject.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "LuaMobileObjectCollisionEvent.h"

#include "TES3Reference.h"

namespace TES3 {
	const auto TES3_MobileObject_onActorCollision = reinterpret_cast<bool(__thiscall *)(MobileObject*, int)>(0x5615A0);
	const auto TES3_MobileObject_onObjectCollision = reinterpret_cast<bool(__thiscall *)(MobileObject*, int, bool)>(0x5615C0);
	const auto TES3_MobileObject_onTerrainCollision = reinterpret_cast<bool(__thiscall *)(MobileObject*, int)>(0x5615E0);
	const auto TES3_MobileObject_onWaterCollision = reinterpret_cast<bool(__thiscall *)(MobileObject*, int)>(0x5615E0);
	const auto TES3_MobileObject_onActivatorCollision = reinterpret_cast<bool(__thiscall *)(MobileObject*, int)>(0x561600);

	bool MobileObject::onActorCollision(int collisionIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->arrayCollisionResults[collisionIndex].colliderRef;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		bool result = TES3_MobileObject_onActorCollision(this, collisionIndex);

		// Fire off our hit event.
		if (mwse::lua::event::MobileObjectCollisionEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));
		}

		return result;
	}

	bool MobileObject::onObjectCollision(int collisionIndex, bool flag) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->arrayCollisionResults[collisionIndex].colliderRef;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		bool result = TES3_MobileObject_onObjectCollision(this, collisionIndex, flag);

		// Fire off our hit event.
		if (mwse::lua::event::MobileObjectCollisionEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));
		}

		return result;
	}

	bool MobileObject::onTerrainCollision(int collisionIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->arrayCollisionResults[collisionIndex].colliderRef;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		bool result = TES3_MobileObject_onTerrainCollision(this, collisionIndex);

		// Fire off our hit event.
		if (mwse::lua::event::MobileObjectCollisionEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));
		}

		return result;
	}

	bool MobileObject::onWaterCollision(int collisionIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->arrayCollisionResults[collisionIndex].colliderRef;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		bool result = TES3_MobileObject_onWaterCollision(this, collisionIndex);

		// Fire off our hit event.
		if (mwse::lua::event::MobileObjectCollisionEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));
		}

		return result;
	}

	bool MobileObject::onActivatorCollision(int collisionIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->arrayCollisionResults[collisionIndex].colliderRef;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		bool result = TES3_MobileObject_onActivatorCollision(this, collisionIndex);

		// Fire off our hit event.
		if (mwse::lua::event::MobileObjectCollisionEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));
		}

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

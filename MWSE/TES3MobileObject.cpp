#include "TES3MobileObject.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "LuaObjectInvalidatedEvent.h"
#include "LuaMobileObjectCollisionEvent.h"

#include "TES3MobileCreature.h"
#include "TES3MobileNPC.h"
#include "TES3MobilePlayer.h"
#include "TES3MobileProjectile.h"
#include "TES3MobileSpellProjectile.h"
#include "TES3Reference.h"

namespace TES3 {

	Vector3 MobileObject::Collision::getNormal() {
		return TES3::Vector3(quantizedNormal[0] * QUANTIZER, quantizedNormal[1] * QUANTIZER, quantizedNormal[2] * QUANTIZER);
	}

#define TES3_vTable_MobileCreature 0x74AFA4
#define TES3_vTable_MobileNPC 0x74AE6C
#define TES3_vTable_MobilePlayer 0x74B174
#define TES3_vTable_MobileProjectile 0x74B2B4
#define TES3_vTable_SpellProjectile 0x74B360

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

	bool MobileObject::isActor() {
		return vTable.mobileObject->isActor(this);
	}

	void MobileObject::enterLeaveSimulation(bool entering) {
		vTable.mobileObject->enterLeaveSimulation(this, entering);
	}

	const auto TES3_MobileObject_enterLeaveSimulationByDistance = reinterpret_cast<void(__thiscall *)(MobileObject*)>(0x55FFC0);
	void MobileObject::enterLeaveSimulationByDistance() {
		TES3_MobileObject_enterLeaveSimulationByDistance(this);
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

	static std::unordered_map<const MobileObject*, sol::object> mobileObjectCache;
	static std::mutex mobileObjectCacheMutex;

	sol::object MobileObject::getOrCreateLuaObject(lua_State* L) const {
		if (this == nullptr) {
			return sol::nil;
		}

		mobileObjectCacheMutex.lock();

		auto cacheHit = mobileObjectCache.find(this);
		if (cacheHit != mobileObjectCache.end()) {
			auto result = cacheHit->second;
			mobileObjectCacheMutex.unlock();
			return result;
		}

		sol::object ref = sol::nil;
		switch ((unsigned int)vTable.mobileObject) {
		case TES3_vTable_MobileCreature:
			ref = sol::make_object(L, static_cast<const TES3::MobileCreature*>(this));
			break;
		case TES3_vTable_MobileNPC:
			ref = sol::make_object(L, static_cast<const TES3::MobileNPC*>(this));
			break;
		case TES3_vTable_MobilePlayer:
			ref = sol::make_object(L, static_cast<const TES3::MobilePlayer*>(this));
			break;
		case TES3_vTable_MobileProjectile:
			ref = sol::make_object(L, static_cast<const TES3::MobileProjectile*>(this));
			break;
		case TES3_vTable_SpellProjectile:
			ref = sol::make_object(L, static_cast<const TES3::MobileSpellProjectile*>(this));
			break;
		}

		mobileObjectCache[this] = ref;
		mobileObjectCacheMutex.unlock();

		return ref;
	}

	void MobileObject::clearCachedLuaObject(const MobileObject* object) {
		if (!mobileObjectCache.empty()) {
			mobileObjectCacheMutex.lock();

			// Clear any events that make use of this object.
			auto it = mobileObjectCache.find(object);
			if (it != mobileObjectCache.end()) {
				// Let people know that this object is invalidated.
				mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::ObjectInvalidatedEvent(it->second));

				// Clear any events that make use of this object.
				mwse::lua::event::clearObjectFilter(it->second);

				// Remove it from the cache.
				mobileObjectCache.erase(it);
			}

			mobileObjectCacheMutex.unlock();
		}
	}

	void MobileObject::clearCachedLuaObjects() {
		mobileObjectCacheMutex.lock();
		mobileObjectCache.clear();
		mobileObjectCacheMutex.unlock();
	}
}

int sol_lua_push(sol::types<TES3::MobileObject>, lua_State* L, const TES3::MobileObject* obj) {
	return obj->getOrCreateLuaObject(L).push(L);
}

int sol_lua_push(sol::types<TES3::MobileObject*>, lua_State* L, const TES3::MobileObject& obj) {
	return obj.getOrCreateLuaObject(L).push(L);
}

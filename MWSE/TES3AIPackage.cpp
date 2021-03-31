#include "TES3AIPackage.h"

#include "LuaManager.h"
#include "LuaObjectInvalidatedEvent.h"

namespace TES3 {
	void AIPackage::simulate() {
		vTable->simulate(this);
	}

	bool AIPackage::movement() {
		return vTable->movement(this);
	}

	bool AIPackage::initialize() {
		return vTable->initialize(this);
	}

	void AIPackage::cleanup() {
		vTable->cleanup(this);
	}

	static std::unordered_map<const AIPackage*, sol::object> AIPackageObjectCache;
	static std::mutex AIPackageObjectCacheMutex;

	sol::object AIPackage::getOrCreateLuaObject(lua_State* L) const {
		if (this == nullptr) {
			return sol::nil;
		}

		AIPackageObjectCacheMutex.lock();

		auto cacheHit = AIPackageObjectCache.find(this);
		if (cacheHit != AIPackageObjectCache.end()) {
			auto result = cacheHit->second;
			AIPackageObjectCacheMutex.unlock();
			return result;
		}

		// Make sure we're looking at the main state.
		L = sol::main_thread(L);

		sol::object ref = sol::nil;
		switch (packageType) {
		case TES3::AIPackageType::Wander:
			ref = sol::make_object(L, static_cast<const TES3::AIPackageWander*>(this));
			break;
		case TES3::AIPackageType::Travel:
			ref = sol::make_object(L, static_cast<const TES3::AIPackageTravel*>(this));
			break;
		case TES3::AIPackageType::Escort:
			ref = sol::make_object(L, static_cast<const TES3::AIPackageEscort*>(this));
			break;
		case TES3::AIPackageType::Follow:
			ref = sol::make_object(L, static_cast<const TES3::AIPackageFollow*>(this));
			break;
		case TES3::AIPackageType::Activate:
			ref = sol::make_object(L, static_cast<const TES3::AIPackageActivate*>(this));
			break;
		default:
			ref = sol::make_object_userdata(L, this);
		}

		if (ref != sol::nil) {
			AIPackageObjectCache[this] = ref;
		}

		AIPackageObjectCacheMutex.unlock();

		return ref;;
	}

	void AIPackage::clearCachedLuaObject(const AIPackage* object) {
		if (!AIPackageObjectCache.empty()) {
			AIPackageObjectCacheMutex.lock();

			// Clear any events that make use of this object.
			auto it = AIPackageObjectCache.find(object);
			if (it != AIPackageObjectCache.end()) {
				// Let people know that this object is invalidated.
				mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::ObjectInvalidatedEvent(it->second));

				// Clear any events that make use of this object.
				mwse::lua::event::clearObjectFilter(it->second);

				// Remove it from the cache.
				AIPackageObjectCache.erase(it);
			}

			AIPackageObjectCacheMutex.unlock();
		}
	}

	void AIPackage::clearCachedLuaObjects() {
		AIPackageObjectCacheMutex.lock();
		AIPackageObjectCache.clear();
		AIPackageObjectCacheMutex.unlock();
	}

	AIPackageType AIPackageConfig::toPackageType() const {
		switch (type) {
		case AIPackageConfigType::Travel:
			return AIPackageType::Travel;
		case AIPackageConfigType::Wander:
			return AIPackageType::Wander;
		case AIPackageConfigType::Escort:
			return AIPackageType::Escort;
		case AIPackageConfigType::Follow:
			return AIPackageType::Follow;
		case AIPackageConfigType::Activate:
			return AIPackageType::Activate;
		}
		return AIPackageType::Wander;
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3_AIPACKAGE(TES3::AIPackage)

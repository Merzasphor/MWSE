#include "TES3Weather.h"

#include "sol.hpp"

#include <mutex>

#include "TES3WeatherController.h"

#include "TES3WeatherAsh.h"
#include "TES3WeatherBlight.h"
#include "TES3WeatherBlizzard.h"
#include "TES3WeatherClear.h"
#include "TES3WeatherCloudy.h"
#include "TES3WeatherFoggy.h"
#include "TES3WeatherOvercast.h"
#include "TES3WeatherRain.h"
#include "TES3WeatherSnow.h"
#include "TES3WeatherThunder.h"

#include "LuaManager.h"

#include "LuaObjectInvalidatedEvent.h"

namespace TES3 {
	static std::unordered_map<const Weather*, sol::object> weatherObjectCache;
	static std::mutex weatherObjectCacheMutex;

	sol::object Weather::getOrCreateLuaObject(lua_State* L, const Weather* object) {
		if (object == nullptr) {
			return sol::nil;
		}

		weatherObjectCacheMutex.lock();

		auto cacheHit = weatherObjectCache.find(object);
		if (cacheHit != weatherObjectCache.end()) {
			auto result = cacheHit->second;
			weatherObjectCacheMutex.unlock();
			return result;
		}

		sol::object ref = sol::nil;
		switch (object->index) {
		case TES3::WeatherType::Ash:
			ref = sol::make_object(L, static_cast<const TES3::WeatherAsh*>(object));
			break;
		case TES3::WeatherType::Blight:
			ref = sol::make_object(L, static_cast<const TES3::WeatherBlight*>(object));
			break;
		case TES3::WeatherType::Blizzard:
			ref = sol::make_object(L, static_cast<const TES3::WeatherBlizzard*>(object));
			break;
		case TES3::WeatherType::Clear:
			ref = sol::make_object(L, static_cast<const TES3::WeatherClear*>(object));
			break;
		case TES3::WeatherType::Cloudy:
			ref = sol::make_object(L, static_cast<const TES3::WeatherCloudy*>(object));
			break;
		case TES3::WeatherType::Foggy:
			ref = sol::make_object(L, static_cast<const TES3::WeatherFoggy*>(object));
			break;
		case TES3::WeatherType::Overcast:
			ref = sol::make_object(L, static_cast<const TES3::WeatherOvercast*>(object));
			break;
		case TES3::WeatherType::Rain:
			ref = sol::make_object(L, static_cast<const TES3::WeatherRain*>(object));
			break;
		case TES3::WeatherType::Snow:
			ref = sol::make_object(L, static_cast<const TES3::WeatherSnow*>(object));
			break;
		case TES3::WeatherType::Thunder:
			ref = sol::make_object(L, static_cast<const TES3::WeatherThunder*>(object));
			break;
		}

		if (ref != sol::nil) {
			weatherObjectCache[object] = ref;
		}

		weatherObjectCacheMutex.unlock();

		return ref;;
	}

	int Weather::pushCachedLuaObject(lua_State* L, const Weather* object) {
		return getOrCreateLuaObject(L, object).push(L);
	}

	void Weather::clearCachedLuaObject(const Weather* object) {
		if (!weatherObjectCache.empty()) {
			weatherObjectCacheMutex.lock();

			// Clear any events that make use of this object.
			auto it = weatherObjectCache.find(object);
			if (it != weatherObjectCache.end()) {
				// Let people know that this object is invalidated.
				mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::ObjectInvalidatedEvent(it->second));

				// Clear any events that make use of this object.
				mwse::lua::event::clearObjectFilter(it->second);

				// Remove it from the cache.
				weatherObjectCache.erase(it);
			}

			weatherObjectCacheMutex.unlock();
		}
	}

	void Weather::clearCachedLuaObjects() {
		weatherObjectCacheMutex.lock();
		weatherObjectCache.clear();
		weatherObjectCacheMutex.unlock();
	}
}

MWSE_SOL_CACHE_WEATHER_TYPE_BODY(TES3::Weather);
MWSE_SOL_CACHE_WEATHER_TYPE_BODY(TES3::WeatherAsh);
MWSE_SOL_CACHE_WEATHER_TYPE_BODY(TES3::WeatherBlight);
MWSE_SOL_CACHE_WEATHER_TYPE_BODY(TES3::WeatherBlizzard);
MWSE_SOL_CACHE_WEATHER_TYPE_BODY(TES3::WeatherClear);
MWSE_SOL_CACHE_WEATHER_TYPE_BODY(TES3::WeatherCloudy);
MWSE_SOL_CACHE_WEATHER_TYPE_BODY(TES3::WeatherFoggy);
MWSE_SOL_CACHE_WEATHER_TYPE_BODY(TES3::WeatherOvercast);
MWSE_SOL_CACHE_WEATHER_TYPE_BODY(TES3::WeatherRain);
MWSE_SOL_CACHE_WEATHER_TYPE_BODY(TES3::WeatherSnow);
MWSE_SOL_CACHE_WEATHER_TYPE_BODY(TES3::WeatherThunder);

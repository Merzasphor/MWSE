#pragma once

#include "TES3Defines.h"

#include "TES3Vectors.h"

namespace TES3 {
	struct Weather_vTable {
		void * deleting;
		void * simulate;
		void * unloadAudio;
		void * transition;
	};

	struct Weather {
		Weather_vTable * vTable; // 0x0
		int index; // 0x4
		float transitionDelta; // 0x8
		float glareView; // 0xC
		WeatherController * controller; // 0x10
		Vector3 ambientSunriseCol; // 0x14
		Vector3 ambientDayCol; // 0x20
		Vector3 ambientSunsetCol; // 0x2C
		Vector3 ambientNightCol; // 0x38
		Vector3 fogSunriseCol; // 0x44
		Vector3 fogDayCol; // 0x50
		Vector3 fogSunsetCol; // 0x5C
		Vector3 fogNightCol; // 0x68
		Vector3 skySunriseCol; // 0x74
		Vector3 skyDayCol; // 0x80
		Vector3 skySunsetCol; // 0x8C
		Vector3 skyNightCol; // 0x98
		Vector3 sunSunriseCol; // 0xA4
		Vector3 sunDayCol; // 0xB0
		Vector3 sunSunsetCol; // 0xBC
		Vector3 sunNightCol; // 0xC8
		Vector3 sundiscSunsetCol; // 0xD4
		int unknown_0xE0;
		Vector3 unknown_0xE4;
		float cloudsMaxPercent; // 0xF0
		float landFogDayDepth; // 0xF4
		float landFogNightDepth; // 0xF8
		float cloudsSpeed; // 0xFC
		float windSpeed; // 0x100
		char texturePathCloud[260]; // 0x104
		int unknown_0x208;
		bool ambientPlaying;
		bool underwaterSoundState;
		char soundIDAmbientLoop[260]; // 0x20E
		Sound * soundAmbientLoop; // 0x314

		//
		// Custom functions.
		//

		bool setCloudTexturePath(const char* path);
		bool setAmbientLoopSoundID(const char* id);

		// Storage for cached userdata.
		static sol::object getOrCreateLuaObject(lua_State* L, const Weather* object);
		static int pushCachedLuaObject(lua_State* L, const Weather* object);
		static void clearCachedLuaObject(const Weather* object);
		static void clearCachedLuaObjects();
	};
	static_assert(sizeof(Weather) == 0x318, "TES3::Weather failed size validation");
}

#define MWSE_SOL_CACHE_WEATHER_TYPE_DEF(T) int sol_lua_push(sol::types<T*>, lua_State* L, const T* object);
#define MWSE_SOL_CACHE_WEATHER_TYPE_BODY(T) int sol_lua_push(sol::types<T*>, lua_State* L, const T* object) { return T::pushCachedLuaObject(L, object); }

MWSE_SOL_CACHE_WEATHER_TYPE_DEF(TES3::Weather);
MWSE_SOL_CACHE_WEATHER_TYPE_DEF(TES3::WeatherAsh);
MWSE_SOL_CACHE_WEATHER_TYPE_DEF(TES3::WeatherBlight);
MWSE_SOL_CACHE_WEATHER_TYPE_DEF(TES3::WeatherBlizzard);
MWSE_SOL_CACHE_WEATHER_TYPE_DEF(TES3::WeatherClear);
MWSE_SOL_CACHE_WEATHER_TYPE_DEF(TES3::WeatherCloudy);
MWSE_SOL_CACHE_WEATHER_TYPE_DEF(TES3::WeatherFoggy);
MWSE_SOL_CACHE_WEATHER_TYPE_DEF(TES3::WeatherOvercast);
MWSE_SOL_CACHE_WEATHER_TYPE_DEF(TES3::WeatherRain);
MWSE_SOL_CACHE_WEATHER_TYPE_DEF(TES3::WeatherSnow);
MWSE_SOL_CACHE_WEATHER_TYPE_DEF(TES3::WeatherThunder);

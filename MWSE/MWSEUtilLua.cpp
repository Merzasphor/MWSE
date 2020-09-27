#include "MWSEUtilLua.h"

#include "LuaManager.h"

#include "BuildDate.h"
#include "MWSEDefs.h"
#include "WindowsUtil.h"

#include "LuaTimer.h"

namespace mwse::lua {
	void crash() {
		// You're not my manager!
		int* x = nullptr;
		*x = 4;
	}

	unsigned int getVersion() {
		return MWSE_VERSION_INTEGER;
	}

	bool overrideScript(const char* scriptId, sol::object target) {
		return LuaManager::getInstance().overrideScript(scriptId, target);
	}

	void bindMWSEUtil() {
		auto& manager = LuaManager::getInstance();
		auto stateHandle = manager.getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;

		// Create our namespace.
		sol::table lua_mwse = state["mwse"];

		// Provide access to our timer collections.
		lua_mwse["realTimers"] = manager.realTimers;
		lua_mwse["simulateTimers"] = manager.simulateTimers;
		lua_mwse["gameTimers"] = manager.gameTimers;

		// Basic value binding.
		lua_mwse["version"] = MWSE_VERSION_INTEGER;
		lua_mwse["buildDate"] = MWSE_BUILD_DATE;
#ifdef APPVEYOR_BUILD_ID
		lua_mwse["buildID"] = APPVEYOR_BUILD_ID;
#else
		lua_mwse["buildID"] = UINT_MAX;
#endif

		// Basic function binding.
		lua_mwse["crash"] = crash;
		lua_mwse["getVersion"] = getVersion;
		lua_mwse["getVirtualMemoryUsage"] = getVirtualMemoryUsage;
		lua_mwse["overrideScript"] = overrideScript;
		lua_mwse["virtualKeyPressed"] = getIsVirtualKeyPressed;
	}
}

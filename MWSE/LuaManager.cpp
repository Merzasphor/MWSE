#include "LuaManager.h"

#include "Log.h"

// Lua binding files. These are split out rather than kept here to help with compile times.
#include "TES3ObjectLua.h"

namespace mwse {
	namespace lua {
		// Initialize singleton.
		LuaManager LuaManager::singleton;

		// LuaManager constructor. This is private, as a singleton.
		LuaManager::LuaManager() {
			// Open default lua libraries.
			luaState.open_libraries();

			// Overwrite the default print function to print to the MWSE log.
			luaState["print"] = [](lua_State* L) {
				log::getLog() << lua_tostring(L, -1) << std::endl;
				lua_pop(L, 1);
				return 0;
			};

			// Bind data types.
			bindTES3Object();

			// Execute mwse_init.lua
			sol::protected_function_result result = luaState.do_file("Data Files/MWSE/lua/mwse_init.lua");
			if (!result.valid()) {
				sol::error err = result;
				log::getLog() << "ERROR: Failed to initialize MWSE Lua interface. Error encountered when executing mwse_init.lua:\n" << err.what() << std::endl;
			}
		}
	}
}
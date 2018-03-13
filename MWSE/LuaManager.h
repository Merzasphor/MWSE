#pragma once

#include "sol.hpp"

namespace mwse {
	namespace lua {
		class LuaManager {
		public:
			// Returns an instance to the singleton.
			static LuaManager& getInstance() {
				return singleton;
			};

			// Returns a reference to the sol2 lua state.
			sol::state& getState() {
				return luaState;
			}

		private:
			LuaManager();

			static LuaManager singleton;

			sol::state luaState;
		};
	}
}

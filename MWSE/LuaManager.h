#pragma once

#include <unordered_map>

#include "LuaUnifiedHeader.h"

namespace mwse {
	namespace lua {
		class LuaManager {
		public:
			// Returns an instance to the singleton.
			static LuaManager& getInstance() {
				return singleton;
			};

			// Returns a reference to the sol2 lua state.
			sol::state& __fastcall getState() {
				return luaState;
			}

			// Uses the MemoryUtil library to create the necessary injections into Morrowind.
			void hook();

			// Performs cleanup to safely detach the DLL.
			void cleanup();

			// Set context for lua scripts.
			TES3::Script* getCurrentScript();
			void setCurrentScript(TES3::Script*);
			TES3::Reference* getCurrentReference();
			void setCurrentReference(TES3::Reference*);

		private:
			LuaManager();

			//
			void bindData();

			// 
			static LuaManager singleton;

			// 
			sol::state luaState;

			//
			TES3::Script* currentScript = NULL;
			TES3::Reference* currentReference = NULL;
		};
	}
}

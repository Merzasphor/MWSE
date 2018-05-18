#pragma once

#include <unordered_map>
#include <queue>

#include <mutex>

#include "TES3Util.h"

#include "LuaUnifiedHeader.h"
#include "LuaEvents.h"

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
#if _DEBUG
				// Prevent us from getting the state from anything but the main thread.
				TES3::DataHandler* dataHandler = tes3::getDataHandler();
				assert(dataHandler == NULL || dataHandler->mainThreadID == GetCurrentThreadId());
#endif
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

			// Event management.
			sol::object triggerEvent(event::BaseEvent*);
			void triggerBackgroundThreadEvents();

			// Handle our button pressed callbacks. There can only be one at a time.
			void setButtonPressedCallback(sol::optional<sol::protected_function>);
			sol::object triggerButtonPressed();

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

			//
			std::mutex backgroundThreadEventsMutex;
			std::queue<event::BaseEvent*> backgroundThreadEvents;

			// Storage for our current button pressed callback.
			sol::protected_function buttonPressedCallback = sol::nil;
		};
	}
}

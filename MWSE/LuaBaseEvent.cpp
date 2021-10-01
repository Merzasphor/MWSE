
#include "LuaBaseEvent.h"

#include "LuaManager.h"

#include "Log.h"

namespace mwse {
	namespace lua {
		namespace event {
			sol::object trigger(const char* eventType, sol::table eventData, sol::object eventOptions) {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;

				// Trigger the function, check for lua errors.
				static sol::protected_function luaEventTrigger = state["event"]["trigger"];
				sol::protected_function_result result = luaEventTrigger(eventType, eventData, eventOptions);
				if (result.valid()) {
					return result;
				}
				else {
					sol::error error = result;
					log::getLog() << "Event system error encountered when raising " << eventType << " event:" << std::endl << error.what() << std::endl;
				}

				return sol::nil;
			}

			void clearObjectFilter(sol::object filterObject) {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;

				static sol::protected_function luaEventClear = state["event"]["clear"];
				luaEventClear(sol::nil, filterObject);
			}
		}
	}
}
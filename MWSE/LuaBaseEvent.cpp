
#include "LuaBaseEvent.h"

#include "LuaManager.h"

#include "Log.h"

namespace mwse {
	namespace lua {
		namespace event {
			sol::object trigger(const char* eventType, sol::table eventData, sol::object eventOptions) {
				sol::state& state = LuaManager::getInstance().getState();

				// Trigger the function, check for lua errors.
				sol::protected_function trigger = state["event"]["trigger"];
				sol::protected_function_result result = trigger(eventType, eventData, eventOptions);
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
				sol::state& state = LuaManager::getInstance().getState();
				sol::protected_function trigger = state["event"]["clear"];
				trigger(sol::nil, filterObject);
			}
		}
	}
}
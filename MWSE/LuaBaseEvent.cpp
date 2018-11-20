
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
				try {
					return trigger(eventType, eventData, eventOptions);
				}
				catch (const std::exception& e) {
					log::getLog() << "Lua error encountered when raising " << eventType << " event:" << std::endl << e.what() << std::endl;
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

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
				auto result = trigger(eventType, eventData, eventOptions);
				if (!result.valid()) {
					sol::error error = result;
					log::getLog() << "Lua error encountered when raising " << eventType << " event:" << std::endl << error.what() << std::endl;
				}

				return result;
			}

			void clearObjectFilter(sol::object filterObject) {
				sol::state& state = LuaManager::getInstance().getState();
				sol::protected_function trigger = state["event"]["clear"];
				trigger(sol::nil, filterObject);
			}
		}
	}
}
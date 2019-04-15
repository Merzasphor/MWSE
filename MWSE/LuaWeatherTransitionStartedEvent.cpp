#include "LuaWeatherTransitionStartedEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Weather.h"
#include "TES3WeatherController.h"
#include "TES3WorldController.h"

namespace mwse {
	namespace lua {
		namespace event {
			WeatherTransitionStartedEvent::WeatherTransitionStartedEvent() :
				GenericEvent("weatherTransitionStarted")
			{

			}

			sol::table WeatherTransitionStartedEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				auto controller = TES3::WorldController::get()->weatherController;

				eventData["from"] = makeLuaObject(controller->currentWeather);
				eventData["to"] = makeLuaObject(controller->nextWeather);

				return eventData;
			}
		}
	}
}

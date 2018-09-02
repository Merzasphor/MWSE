#include "LuaWeatherChangedImmediateEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3WeatherController.h"
#include "TES3WorldController.h"

namespace mwse {
	namespace lua {
		namespace event {
			WeatherChangedImmediateEvent::WeatherChangedImmediateEvent() :
				GenericEvent("weatherChangedImmediate")
			{

			}

			sol::table WeatherChangedImmediateEvent::createEventTable() {
				sol::table eventData = LuaManager::getInstance().getState().create_table();
				auto controller = tes3::getWorldController()->weatherController;

				eventData["to"] = makeLuaObject(controller->currentWeather);

				return eventData;
			}
		}
	}
}

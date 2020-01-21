#include "LuaCalcSunDamageScalarEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3WeatherController.h"

namespace mwse {
    namespace lua {
        namespace event {
            CalcSunDamageScalarEvent::CalcSunDamageScalarEvent(float sunDamage) :
                GenericEvent("calcSunDamageScalar"),
                m_SunDamage(sunDamage)
            {

            }

            sol::table CalcSunDamageScalarEvent::createEventTable() {
                auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
                sol::state& state = stateHandle.state;
                sol::table eventData = state.create_table();

                eventData["sunDamage"] = m_SunDamage;

                return eventData;
            }

            bool CalcSunDamageScalarEvent::m_EventEnabled = false;
        }
    }
}
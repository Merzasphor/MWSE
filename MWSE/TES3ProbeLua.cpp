#include "TES3ProbeLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Probe.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Probe() {
			LuaManager::getInstance().getState().new_usertype<TES3::Probe>("TES3Probe",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::base_classes, sol::bases<TES3::Item, TES3::BaseObject>(),

				sol::meta_function::to_string, &TES3::Probe::getObjectID,

				//
				// Properties.
				//

				"objectType", &TES3::Probe::objectType,

				"boundingBox", &TES3::Probe::boundingBox,

				"id", sol::readonly_property(&TES3::Probe::getObjectID),
				"name", sol::property(&TES3::Probe::getName, &TES3::Probe::setName),

				"icon", sol::readonly_property(&TES3::Probe::getIconPath),
				"model", sol::readonly_property(&TES3::Probe::getModelPath),

				"value", sol::readonly_property(&TES3::Probe::getValue),
				"weight", sol::readonly_property(&TES3::Probe::getWeight),
				"quality", &TES3::Probe::quality,
				"condition", &TES3::Probe::maxCondition,

				"script", sol::readonly_property(&TES3::Probe::getScript)

				);
		}
	}
}

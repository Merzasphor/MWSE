#include "TES3ActivatorLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Activator() {
			LuaManager::getInstance().getState().new_usertype<TES3::Activator>("TES3Activator",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Activator::objectType,

				"boundingBox", &TES3::Activator::boundingBox,

				"id", sol::readonly_property(&TES3::Activator::getObjectID),
				"name", sol::property(&TES3::Activator::getName, &TES3::Activator::setName),

				"model", sol::readonly_property(&TES3::Activator::getModelPath),

				"script", sol::readonly_property(&TES3::Activator::getScript)

				);
		}
	}
}

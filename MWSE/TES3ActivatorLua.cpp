#include "TES3ActivatorLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Activator() {
			LuaManager::getInstance().getState().new_usertype<TES3::Activator>("TES3Activator",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::base_classes, sol::bases<TES3::BaseObject>(),

				sol::meta_function::to_string, &TES3::Activator::getObjectID,

				//
				// Properties.
				//

				"objectType", sol::readonly_property(&TES3::Activator::objectType),

				"boundingBox", sol::readonly_property(&TES3::Activator::boundingBox),

				"id", sol::readonly_property(&TES3::Activator::getObjectID),
				"name", sol::property(&TES3::Activator::getName, &TES3::Activator::setName),

				"model", sol::readonly_property(&TES3::Activator::getModelPath),

				"script", sol::readonly_property(&TES3::Activator::getScript)

				);
		}
	}
}

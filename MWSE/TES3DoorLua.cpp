#include "TES3DoorLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Door.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Door() {
			LuaManager::getInstance().getState().new_usertype<TES3::Door>("TES3Door",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::base_classes, sol::bases<TES3::BaseObject>(),

				sol::meta_function::to_string, &TES3::Door::getObjectID,

				//
				// Properties.
				//

				"objectType", &TES3::Door::objectType,

				"boundingBox", &TES3::Door::boundingBox,

				"id", sol::readonly_property(&TES3::Door::getObjectID),
				"name", sol::property(&TES3::Door::getName, &TES3::Door::setName),

				"model", sol::readonly_property(&TES3::Door::getModelPath),

				"script", sol::readonly_property(&TES3::Door::getScript)

				);
		}
	}
}

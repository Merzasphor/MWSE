#include "TES3DoorLua.h"

#include "LuaManager.h"

#include "TES3Door.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Door() {
			LuaManager::getInstance().getState().new_usertype<TES3::Door>("TES3Door",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Door::objectType,

				"id", sol::readonly_property(&TES3::Door::getObjectID),
				"name", sol::property(&TES3::Door::getName, &TES3::Door::setName),

				"model", sol::readonly_property(&TES3::Door::getModelPath),

				"script", sol::readonly_property(&TES3::Door::getScript)

				);
		}
	}
}

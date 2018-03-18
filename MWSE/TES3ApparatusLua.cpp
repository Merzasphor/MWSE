#include "TES3ApparatusLua.h"

#include "LuaManager.h"

#include "TES3Apparatus.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Apparatus() {
			LuaManager::getInstance().getState().new_usertype<TES3::Apparatus>("TES3Apparatus",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Apparatus::objectType,

				"id", sol::readonly_property(&TES3::Apparatus::getObjectID),
				"name", sol::property(&TES3::Apparatus::getName, &TES3::Apparatus::setName),

				"icon", sol::readonly_property(&TES3::Apparatus::getIconPath),
				"model", sol::readonly_property(&TES3::Apparatus::getModelPath),

				"type", sol::readonly_property(&TES3::Apparatus::getType),
				"typeName", sol::readonly_property(&TES3::Apparatus::getTypeName),
				"quality", sol::readonly_property(&TES3::Apparatus::getQuality),
				"value", sol::readonly_property(&TES3::Apparatus::getValue),
				"weight", sol::readonly_property(&TES3::Apparatus::getWeight),

				"script", sol::readonly_property(&TES3::Apparatus::getScript)

				);
		}
	}
}

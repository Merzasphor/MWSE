#include "TES3ApparatusLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Apparatus() {
			LuaManager::getInstance().getState().new_usertype<TES3::Apparatus>("TES3Apparatus",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::base_classes, sol::bases<TES3::Item, TES3::BaseObject>(),

				sol::meta_function::to_string, &TES3::Apparatus::getObjectID,

				//
				// Properties.
				//

				"objectType", &TES3::Apparatus::objectType,

				"boundingBox", &TES3::Apparatus::boundingBox,

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

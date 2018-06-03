#include "TES3BookLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Book() {
			LuaManager::getInstance().getState().new_usertype<TES3::Book>("TES3Book",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::base_classes, sol::bases<TES3::Item, TES3::BaseObject>(),

				sol::meta_function::to_string, &TES3::Book::getObjectID,

				//
				// Properties.
				//

				"objectType", &TES3::Book::objectType,

				"boundingBox", &TES3::Book::boundingBox,

				"id", sol::readonly_property(&TES3::Book::getObjectID),
				"name", sol::property(&TES3::Book::getName, &TES3::Book::setName),

				"icon", sol::readonly_property(&TES3::Book::getIconPath),
				"model", sol::readonly_property(&TES3::Book::getModelPath),

				"value", sol::readonly_property(&TES3::Book::getValue),
				"weight", sol::readonly_property(&TES3::Book::getWeight),

				"type", sol::readonly_property(&TES3::Book::bookType),
				"skill", &TES3::Book::skillToRaise,

				"text", sol::readonly_property(&TES3::Book::getBookText),

				"enchantCapacity", &TES3::Book::enchantCapacity,
				"enchantment", sol::property(&TES3::Book::getEnchantment, &TES3::Book::setEnchantment),

				"script", sol::readonly_property(&TES3::Book::getScript)

				);
		}
	}
}

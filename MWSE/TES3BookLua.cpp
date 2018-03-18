#include "TES3BookLua.h"

#include "LuaManager.h"

#include "TES3Book.h"
#include "TES3Enchantment.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Book() {
			auto type = LuaManager::getInstance().getState().new_usertype<TES3::Book>("TES3Book",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Book::objectType,

				"id", sol::readonly_property(&TES3::Book::getObjectID),
				"name", sol::property(&TES3::Book::getName, &TES3::Book::setName),

				"icon", sol::readonly_property(&TES3::Book::getIconPath),
				"model", sol::readonly_property(&TES3::Book::getModelPath),

				"value", sol::readonly_property(&TES3::Book::getValue),
				"weight", sol::readonly_property(&TES3::Book::getWeight),

				"type", sol::readonly_property(&TES3::Book::bookType),
				"skill", &TES3::Book::skillToRaise,

				"text", sol::readonly_property(&TES3::Book::getBookText),

				"enchantment", &TES3::Book::enchantCapacity,
				"enchanting", sol::property(&TES3::Book::getEnchantment, &TES3::Book::setEnchantment),

				"script", sol::readonly_property(&TES3::Book::getScript)

				);
		}
	}
}

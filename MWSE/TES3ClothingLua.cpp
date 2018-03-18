#include "TES3ClothingLua.h"

#include "LuaManager.h"

#include "TES3Clothing.h"
#include "TES3Enchantment.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Clothing() {
			auto type = LuaManager::getInstance().getState().new_usertype<TES3::Clothing>("TES3Clothing",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Clothing::objectType,

				"id", sol::readonly_property(&TES3::Clothing::getObjectID),
				"name", sol::property(&TES3::Clothing::getName, &TES3::Clothing::setName),

				"icon", sol::readonly_property(&TES3::Clothing::getIconPath),
				"model", sol::readonly_property(&TES3::Clothing::getModelPath),

				"slot", sol::readonly_property(&TES3::Clothing::getType),
				"slotName", sol::readonly_property(&TES3::Clothing::getTypeName),
				"isLeftPart", sol::readonly_property(&TES3::Clothing::isLeftPartOfPair),

				"weight", sol::readonly_property(&TES3::Clothing::getWeight),
				"value", sol::readonly_property(&TES3::Clothing::getValue),
				"health", sol::readonly_property(&TES3::Clothing::getDurability),

				"enchantCapacity", &TES3::Clothing::enchantCapacity,
				"enchantment", sol::property(&TES3::Clothing::getEnchantment, &TES3::Clothing::setEnchantment),

				"script", sol::readonly_property(&TES3::Clothing::getScript)

				);
		}
	}
}

#include "TES3ClothingLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Clothing() {
			LuaManager::getInstance().getState().new_usertype<TES3::Clothing>("TES3Clothing",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::base_classes, sol::bases<TES3::Item, TES3::BaseObject>(),

				sol::meta_function::to_string, &TES3::Clothing::getObjectID,

				//
				// Properties.
				//

				"objectType", &TES3::Clothing::objectType,

				"boundingBox", &TES3::Clothing::boundingBox,

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
